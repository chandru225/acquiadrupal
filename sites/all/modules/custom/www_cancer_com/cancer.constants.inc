<?php

/**
 * @file
 * Define all the Constants used for the site.
 */

define('WWW_CANCER_COM_MAIN_MENU', 'jcr-menu-main-menu');
define('WWW_CANCER_COM_CANCERTYPE_DEFAULT_URL', 'cancer-information');

// UUID for the webform used for user profile/registration.
define('WWW_CANCER_COM_REGISTER_FORM_UUID', 'c2b7f18d-e35a-46f8-9389-b3fb38fdb7a4');

// UUID for the webform used for email verification.
define('WWW_CANCER_COM_EMAIL_VERIFY_FORM_UUID', '50e4a73d-f73d-416a-89b0-d80335715946');

// Webform UUIDs for the Eloqua submission.
const CANCER_ELOQUA_FORMS = [
  'f5749ea6-4e53-4c46-abeb-c42c2479b721',
  '8ef88028-1a5e-4e3d-858b-78b7812e0389',
  'b48f8dc7-786f-433a-ba1c-048a8f252a19',
];

/**
 * MAPPING USED IN THE SITE.
 */

// MAPPING: Janrain => Eloqua; Customer Type.
const CANCER_ELOQUA_CUST_TYPE = [
  'patient' => '1',
  'nurse' => '3',
  'doctor' => '2',
  'other' => '0',
];

// MAPPING: Janrain => Eloqua; Customer AGE.
const CANCER_ELOQUA_AGE = [
  '18-24' => '1514',
  '25-34' => '1515',
  '35-44' => '812',
  '45-54' => '813',
  '55-64' => '814',
  '65-74' => '965',
  '75-84' => '1518',
  '85-up' => '1519',
];

// MAPPING: Janrain => Eloqua; Cancer Journey Step.
const CANCER_ELOQUA_CANCER_JOURNEY = [
  'recently-diagnosed' => '1520',
  'treatment-decisions' => '1521',
  'during-treatment' => '1522',
  'remission' => '1523',
  'facing-recurrence' => '1524',
];

// MAPPING: Janrain => Eloqua; Cancer Topics/Interests.
const CANCER_ELOQUA_CANCER_TOPICS = [
  'coping_with_cancer' => '1501',
  'taking_nextstep' => '1508',
  'treatment_options' => '1502',
  'treatment_what_to_expect' => '1509',
  'treatment_isnt_option' => '1503',
  'livingwell' => '1510',
  'caregiving' => '1504',
  'treatment_sideeffects' => '1511',
  'followup' => '1505',
  'treatment_effects' => '1512',
  'cancer_returns' => '1506',
  'treatment_recurring' => '1513',
  'endoflife_care' => '1507',
];

// MAPPING: Janrain => Eloqua; CancerType.
const CANCER_ELOQUA_CANCER_TYPE = [
  'bladder' => '1660',
  'breast' => '1494',
  'lung' => '1495',
  'multiple-myeloma' => '1496',
  'non-hodgkin-lymphoma' => '1497',
  'chronic-lymphocytic-leukemia' => '1657',
  'diffuse-large-bcell-lymphoma' => '1658',
  'follicular-lymphoma' => '1659',
  'prostate' => '1498',
  'other' => '89',
];

// MAPPING: Janrain => Website; CancerType to URLs of the site.
const CANCER_TYPE_HOME_PAGES = [
  'bladder' => 'bladder-cancer',
  'breast' => 'breast-cancer',
  'lung' => 'lung-cancer',
  'multiple-myeloma' => 'multiple-myeloma',
  'non-hodgkin-lymphoma' => 'non-hodgkins-lymphoma',
  'chronic-lymphocytic-leukemia' => 'chronic-lymphocytic-leukemia',
  'diffuse-large-bcell-lymphoma' => 'diffuse-large-bcell-lymphoma',
  'follicular-lymphoma' => 'follicular-lymphoma',
  'prostate' => 'prostate-cancer',
  'other' => 'cancer-information',
];

// MAPPING: Janrain => Acquia Playbook Segment; CancerType.
const CANCER_TYPE_SEGMENT_NAMES = [
  'bladder' =>'Bladder Cancer',
  'breast' => 'Breast',
  'lung' => 'Lung Cancer',
  'multiple-myeloma' => 'Multiple Myeloma',
  'non-hodgkin-lymphoma' => 'Non-Hodgkin Lymphoma',
  'chronic-lymphocytic-leukemia' => '--Chronic Lymphocytic Leukemia (CLL)',
  'diffuse-large-bcell-lymphoma' => '--Diffuse Large B-Cell Lymphoma (DLBCL)',
  'follicular-lymphoma' => '--Follicular Lymphoma (FL)',
  'prostate' => 'Prostate',
  'other' => 'Tumor Agnostic',
];

// MAPPING: User Registration Interest to taxonomies.
const CANCER_USER_REGISTRATION_TOPICS = [
  'coping_with_cancer' => 'Recent Dx: Coping With Cancer',
  'taking_nextstep' => 'Recent Dx: Next Step Toward Treatment',
  'treatment_options' => 'Tx Decisions: Making a Decision',
  'treatment_what_to_expect' => 'Tx Decisions: What to Expect',
  'treatment_isnt_option' => 'Tx Decisions: When Tx Isn’t an Option',
  'livingwell' => 'During Tx: Living Well',
  'caregiving' => 'During Tx: Caregiving',
  'treatment_sideeffects' => 'During Tx: Side Effects of Tx',
  'followup' => 'Remission: Follow-up Care',
  'treatment_effects' => 'Remission: Effects of Treatment',
  'cancer_returns' => 'Recurrence: If Cancer Returns',
  'treatment_recurring' => 'Recurrence: Recurrent Tx Options',
  'endoflife_care' => 'Recurrence: End-of-Life Care',
];
