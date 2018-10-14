<?php
/**
 * @file
 * feature_ct_my_projects.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_ct_my_projects_node_info() {
  $items = array(
    'projects' => array(
      'name' => t('Projects'),
      'base' => 'node_content',
      'description' => t('List of projects created by me'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
