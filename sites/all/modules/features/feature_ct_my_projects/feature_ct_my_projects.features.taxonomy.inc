<?php
/**
 * @file
 * feature_ct_my_projects.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_ct_my_projects_taxonomy_default_vocabularies() {
  return array(
    'back_end_techologies' => array(
      'name' => 'Back End Techologies',
      'machine_name' => 'back_end_techologies',
      'description' => 'List of Back End Technologies',
      'hierarchy' => 0,
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
    'front_end_technologies' => array(
      'name' => 'Front End Technologies',
      'machine_name' => 'front_end_technologies',
      'description' => 'List of Front End Technologies',
      'hierarchy' => 0,
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
