<?php
/**
 * @file
 * feature_views_about_me.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_views_about_me_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'about_me';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'About Me';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'About Me';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Field: Content: WhoamI */
  $handler->display->display_options['fields']['field_whoami']['id'] = 'field_whoami';
  $handler->display->display_options['fields']['field_whoami']['table'] = 'field_data_field_whoami';
  $handler->display->display_options['fields']['field_whoami']['field'] = 'field_whoami';
  $handler->display->display_options['fields']['field_whoami']['label'] = '';
  $handler->display->display_options['fields']['field_whoami']['element_label_colon'] = FALSE;
  /* Field: Content: Academic Details */
  $handler->display->display_options['fields']['field_academic_details']['id'] = 'field_academic_details';
  $handler->display->display_options['fields']['field_academic_details']['table'] = 'field_data_field_academic_details';
  $handler->display->display_options['fields']['field_academic_details']['field'] = 'field_academic_details';
  $handler->display->display_options['fields']['field_academic_details']['label'] = '';
  $handler->display->display_options['fields']['field_academic_details']['element_label_colon'] = FALSE;
  /* Field: Content: Technical Skills */
  $handler->display->display_options['fields']['field_technical_skills_new']['id'] = 'field_technical_skills_new';
  $handler->display->display_options['fields']['field_technical_skills_new']['table'] = 'field_data_field_technical_skills_new';
  $handler->display->display_options['fields']['field_technical_skills_new']['field'] = 'field_technical_skills_new';
  $handler->display->display_options['fields']['field_technical_skills_new']['settings'] = array(
    'add' => '',
    'edit' => '',
    'translate' => '',
    'delete' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_technical_skills_new']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_technical_skills_new']['separator'] = '';
  /* Field: Content: Certificates */
  $handler->display->display_options['fields']['field_certificates']['id'] = 'field_certificates';
  $handler->display->display_options['fields']['field_certificates']['table'] = 'field_data_field_certificates';
  $handler->display->display_options['fields']['field_certificates']['field'] = 'field_certificates';
  $handler->display->display_options['fields']['field_certificates']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_certificates']['settings'] = array(
    'image_style' => 'thumbnail',
  );
  $handler->display->display_options['fields']['field_certificates']['delta_offset'] = '0';
  /* Field: Content: My Projects */
  $handler->display->display_options['fields']['field_my_projects']['id'] = 'field_my_projects';
  $handler->display->display_options['fields']['field_my_projects']['table'] = 'field_data_field_my_projects';
  $handler->display->display_options['fields']['field_my_projects']['field'] = 'field_my_projects';
  $handler->display->display_options['fields']['field_my_projects']['label'] = '';
  $handler->display->display_options['fields']['field_my_projects']['element_class'] = 'project-link';
  $handler->display->display_options['fields']['field_my_projects']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_my_projects']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'about_me' => 'about_me',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'myprofile';
  $export['about_me'] = $view;

  return $export;
}
