<?php
/**
 * @file
 * feature_create_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_create_blog_taxonomy_default_vocabularies() {
  return array(
    'domain' => array(
      'name' => 'Domain',
      'machine_name' => 'domain',
      'description' => 'This will have list of technical and non technical domains',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
