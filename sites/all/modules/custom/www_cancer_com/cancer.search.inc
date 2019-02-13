<?php

/**
 * @file
 * Define functions required to alter search features for the site.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function www_cancer_com_form_apachesolr_panels_search_form_alter(&$form, &$form_state) {
  // Support the Apache Solr Autocomplete module if it exists.
  if (module_exists('apachesolr_autocomplete')) {
    $element = &$form['apachesolr_panels_search_form'];
    $context_id = 'apachesolr_search_page:' . apachesolr_search_default_search_page();
    apachesolr_autocomplete_do_alter($element, $form, $context_id);
  }
  $form['apachesolr_panels_search_form']['#attributes']['placeholder'] = t('SEARCH');
  $form['actions']['submit']['#value'] = t('GO');
  $form['actions']['submit']['#id'] = 'solr-submit';
  $form['#submit'][] = 'www_cancer_com_search_form_submit';

  $sparams = drupal_get_query_parameters();
  $form['actions']['retain-filters'] = array(
    '#type' => 'checkbox',
    '#title' => t('Search Within Current Results'),
    '#default_value' => (int) !empty($sparams['retain-filters']),
  );
}

/**
 * Process the search form submission.
 */
function www_cancer_com_search_form_submit($form, &$form_state) {
  $form_state['no_redirect'] = FALSE;
  $sparams = drupal_get_query_parameters();
  if (empty($form_state['values']['retain-filters'])) {
    $sparams = array();
  }
  else {
    $sparams['retain-filters'] = 1;
  }

  $redirect = 'search/solr/' . trim($form_state['values']['apachesolr_panels_search_form']);
  // Add the query values into the redirect.
  $form_state['redirect'] = array($redirect, array('query' => $sparams));
}

/**
 * Implements hook_facet_items_alter().
 */
function www_cancer_com_facet_items_alter(&$build, &$settings) {
  $facet = $settings->facet;

  if ($facet === 'im_field_newscred_cancer_type' || $facet === 'im_field_newscred_journey_step') {
    // Get JCR Term name & fetch the tags under this.
    $term_name = ($facet === 'im_field_newscred_cancer_type') ? 'Cancer Type' : 'Journey Step';

    $jcr_filter_items = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('general_tags')->vid, key(taxonomy_get_term_by_name($term_name)), 2);
    
    // Get the existing filters from URL.
    $existing_filters = drupal_get_query_parameters();
    $filter = (isset($existing_filters['f'])) ? $existing_filters['f'] : [];

    $options = [];

    foreach ($jcr_filter_items as $item) {
      $query = $filter;

      // Get the field index. 0 for type & 1 for journey.
      $index = ($facet === 'im_field_newscred_cancer_type') ? 0 : 1;

      // Set the query string for this.
      $query[$index] = 'im_field_general_tags:' . $item->tid;

      // Check if this should be active. Check if URL has this param present.
      $active = (isset($filter[$index]) && ($filter[$index] == $query[$index])) ? 1 : 0;

      // Modify Cancer names for NHL subtypes & Journey steps.

      $cancer_name = _valid_menu_trail_alias(current(taxonomy_get_term_by_name($item->name)));
      $item->name = $cancer_name['search-label'];

      if(taxonomy_get_parents($item->tid))
      // Create the option item.
      $options[$item->tid] = [
        '#markup' => $item->name,
        '#path' => request_path(),
        '#html' => FALSE,
        '#indexed_value' => $item->tid,
        '#count' => 0,
        '#active' => $active,
        '#query' => [
          'f' => $query,
        ],
      ];
    }
    $build = $options;
  }
}

/**
 * Implements hook_drupal_goto_alter().
 */
function www_cancer_com_drupal_goto_alter(&$path, &$options, &$http_response_code) {
  if ($path === 'search/site') {
    $path = 'search/solr';
  }
}

/**
 * Implements hook_apachesolr_search_page_alter().
 */
function www_cancer_com_apachesolr_search_page_alter($build, $search_page) {
  $is_core_search = drupal_match_path(request_path(), 'search/site*');
  if ($is_core_search) {
    drupal_goto('search/solr/' . arg(2));
  }
}
