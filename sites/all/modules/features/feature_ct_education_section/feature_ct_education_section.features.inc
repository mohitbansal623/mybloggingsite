<?php
/**
 * @file
 * feature_ct_education_section.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_ct_education_section_node_info() {
  $items = array(
    'education_section' => array(
      'name' => t('Education Section'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
