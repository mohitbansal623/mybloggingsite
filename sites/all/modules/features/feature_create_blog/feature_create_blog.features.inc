<?php
/**
 * @file
 * feature_create_blog.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_create_blog_node_info() {
  $items = array(
    'create_blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('This is an interface where we can write a blog'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
