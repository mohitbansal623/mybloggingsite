<?php
/**
 * @file
 * feature_views_my_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_views_my_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['row-start-open'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Front End Technologies */
  $handler->display->display_options['fields']['field_front_end_technologies']['id'] = 'field_front_end_technologies';
  $handler->display->display_options['fields']['field_front_end_technologies']['table'] = 'field_data_field_front_end_technologies';
  $handler->display->display_options['fields']['field_front_end_technologies']['field'] = 'field_front_end_technologies';
  $handler->display->display_options['fields']['field_front_end_technologies']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_front_end_technologies']['delta_offset'] = '0';
  /* Field: Content: Back End Technologies */
  $handler->display->display_options['fields']['field_back_end_technologies']['id'] = 'field_back_end_technologies';
  $handler->display->display_options['fields']['field_back_end_technologies']['table'] = 'field_data_field_back_end_technologies';
  $handler->display->display_options['fields']['field_back_end_technologies']['field'] = 'field_back_end_technologies';
  $handler->display->display_options['fields']['field_back_end_technologies']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_back_end_technologies']['delta_offset'] = '0';
  /* Field: Content: Project Description */
  $handler->display->display_options['fields']['field_project_description']['id'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['table'] = 'field_data_field_project_description';
  $handler->display->display_options['fields']['field_project_description']['field'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['alter']['max_length'] = '100';
  /* Field: Content: Project Link */
  $handler->display->display_options['fields']['field_project_link']['id'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['table'] = 'field_data_field_project_link';
  $handler->display->display_options['fields']['field_project_link']['field'] = 'field_project_link';
  $handler->display->display_options['fields']['field_project_link']['label'] = '';
  $handler->display->display_options['fields']['field_project_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_link']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '0';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'projects' => 'projects',
  );

  /* Display: My Projects */
  $handler = $view->new_display('page', 'My Projects', 'my_projects');
  $handler->display->display_options['path'] = 'myprojects';
  $export['my_profile'] = $view;

  return $export;
}
