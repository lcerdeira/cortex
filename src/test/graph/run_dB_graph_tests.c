#include <test_dB_graph.h>
#include <test_file_reader.h>
#include <test_cyclic_count.h>


#include <CUnit.h>
#include <Basic.h>

int  main()
{

  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS!=CU_initialize_registry())
    return CU_get_error();
  
  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite_1", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */

  
  if (NULL == CU_add_test(pSuite, "test hash_table_find for dB_graphs",  test_hash_table_find)){
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "test tip clipping",  test_tip_clipping)){
    CU_cleanup_registry();
    return CU_get_error();
  }


  if (NULL == CU_add_test(pSuite, "test node prune",  test_node_prunning_low_coverage)){
    CU_cleanup_registry();
    return CU_get_error();
  }
     
  if (NULL == CU_add_test(pSuite, "test get perfect path",  test_get_perfect_path)){
    CU_cleanup_registry();
    return CU_get_error();
  } 

  
  if (NULL == CU_add_test(pSuite, "test writting/reading binary",  test_writing_reading_binary)){
    CU_cleanup_registry();
    return CU_get_error();
  }
  
  if (NULL == CU_add_test(pSuite, "test get detect and smoothe bubble",  test_detect_and_smoothe_bubble)){
     CU_cleanup_registry();
     return CU_get_error();
   }

  // if (NULL == CU_add_test(pSuite, "test nodes are have coverage correctly makred on file loading",  test_coverage_is_correctly_counted_on_loading_from_file) ){
  // CU_cleanup_registry();
  // return CU_get_error();
  //}

   if (NULL == CU_add_test(pSuite, "test has precisely n edges with status",test_db_graph_db_node_has_precisely_n_edges_with_status)){
     CU_cleanup_registry();
     return CU_get_error();
   }




   if (NULL == CU_add_test(pSuite, "test dumping/reading binary",  test_dump_load_binary)){
     CU_cleanup_registry();
     return CU_get_error();
   }

  

   if (NULL == CU_add_test(pSuite, "test calculation of N50",  test_get_N50)){
    CU_cleanup_registry();
    return CU_get_error();
  }


   //if (NULL == CU_add_test(pSuite, "test function for rotating/shifting binary kmers",  test_rotate)){
   // CU_cleanup_registry();
   // return CU_get_error();
   //}
   
      
   if (NULL == CU_add_test(pSuite, "test is condition true for all nodes in supernode",  test_is_condition_true_for_all_nodes_in_supernode)){
     CU_cleanup_registry();
     return CU_get_error();
   }

   if (NULL == CU_add_test(pSuite, "test that can spot supernode that does not intersect any chromosome (with small but real chromosomal data)",  test_read_chromosome_fasta_and_mark_status_of_graph_nodes_as_existing_in_reference))
     {
       CU_cleanup_registry();
       return CU_get_error();
     }

   if (NULL == CU_add_test(pSuite, "Test can pull out supernode that overlaps chromosome1 at start and end but not middle",  test_indel_discovery_simple_test_1)){
     CU_cleanup_registry();
     return CU_get_error();
   }


   //  COMMENTING THIS OUT AS WE HAVE A BETTER ALGORITHM COMING SOON
   //if (NULL == CU_add_test(pSuite, "Test can pull out supernode containing a deletion from chromosome", test_deletion_validation)){
   //  CU_cleanup_registry();
   //  return CU_get_error();
  // }
   


  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
 
  CU_cleanup_registry();
  return CU_get_error();


}





