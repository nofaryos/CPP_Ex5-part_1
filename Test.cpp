

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <string>
#include "doctest.h"
#include "BinaryTree.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Test for the function begin_preorder()"){
	//A short test for the function begin_preorder() before using it in the next TEST_CASE
	
	BinaryTree<int> tree; //creating empty tree
	CHECK_NOTHROW(tree.begin_preorder()); 
	CHECK(tree.begin_preorder() == nullptr); //the root is null
	
	tree.add_root(0); //adding root to the tree
	CHECK_NOTHROW(tree.begin_preorder()); 
	CHECK_EQ(*(tree.begin_preorder()), 0); // check that the root has been updated
}
	
TEST_CASE("Test for the function add_root"){	
	
	// tree of ints:
	BinaryTree<int> tree_of_ints;
	
	for (int i = 0; i < 6; i++){
		CHECK_NOTHROW(tree_of_ints.add_root(i)); //update new root;
		auto it_int = tree_of_ints.begin_preorder();
		CHECK(*(it_int) == i); // check that the root has been updated
	}
	
	// tree of doubles:
	BinaryTree<double> tree_of_doubles;
	
	for (double i = 0.5; i < 6.5; i++){
		CHECK_NOTHROW(tree_of_doubles.add_root(i)); //update new root;
		auto it_double = tree_of_doubles.begin_preorder();
		CHECK(*(it_double) == i); // check that the root has been updated
	}
	
	//tree of strings	
	BinaryTree<string> tree_of_strings;	
	string roots_str[] = {"1","2","3","4","5","6"};
	
	for(int i = 0; i < sizeof(roots_str)/ sizeof(roots_str[0]); i++){		
		CHECK_NOTHROW(tree_of_strings.add_root(roots_str[i])); //update new root;
		auto it_string = tree_of_strings.begin_preorder();
		CHECK_EQ(*(it_string), roots_str[i]); // check that the root has been updated
	}
	
	//tree of chars	
	BinaryTree<char> tree_of_char;	
	char roots_char[] = {'1','2','3','4','5','6'};
	
	for(int i = 0; i < sizeof(roots_char)/ sizeof(roots_char[0]); i++){		
		CHECK_NOTHROW(tree_of_char.add_root(roots_char[i])); //update new root;
		auto it_char = tree_of_char.begin_preorder();
		CHECK_EQ(*(it_char), roots_char[i]); // check that the root has been updated
	}		
}


TEST_CASE("Test for the functions begin_postorder and end_postorder"){
	//A short test to the function begin_postorder and end_postorder
    //before using it in the next TEST_CASES
	
	BinaryTree<int> tree; //creating empty tree
	CHECK_NOTHROW(tree.begin_postorder());
	CHECK_NOTHROW(tree.end_postorder());	
	CHECK_EQ(tree.begin_postorder(), nullptr); //the root is null	
	CHECK_EQ(tree.end_postorder(), nullptr); //the last vertex is always null 
	
	tree.add_root(0); //update the root
	CHECK_NOTHROW(tree.begin_postorder());
	CHECK_EQ(*(tree.begin_postorder()), 0); // check that the root has been updated
	CHECK_EQ(tree.end_postorder(), nullptr); //the last vertex is always null 
	
	tree.add_left(0, 1); // update left child
	CHECK_NOTHROW(tree.begin_postorder());
	CHECK_EQ(*(tree.begin_postorder()), 1); // check that the left child has been updated 
	CHECK_EQ(tree.end_postorder(), nullptr); //the last vertex is always null 	
}


TEST_CASE("Test for the function add_left"){
	
	BinaryTree<int> tree_of_ints; 
	int numOfVertices  = 6; // num of Vertices in the tree
	
	// creating the root of the tree
	tree_of_ints.add_root(0);
	
    // adding left childs                                               // The Tree:
	for(int i = 0; i < numOfVertices; i++){                        //            0
		int j = i + 1;                                        //           1
	    //try adding left child to vertex that not exists        //         2
		//in the tree                                       //        3
		CHECK_THROWS(tree_of_ints.add_left(j , i));        //      4 
        //adding left child to exist vertex                       //    5                                 		
		CHECK_NOTHROW(tree_of_ints.add_left(i , j));     //  6 
	}                                                          
                                                             
	int val = numOfVertices;
	// Check that all vertices have indeed been added to the tree  
	for(auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it){
		CHECK_EQ(*(it), val);
		val --;
	}
    
	/*
	Check that if a left child is added to a vertex 
	that already has a left child then the left child is updated to 
	the new left vertex 
	*/                                                                        //The new tree:
	for(int i = 0; i < numOfVertices*100; i= i + 100){                       //         0 
		int j = i + 100;                                                //       100 
		 //try adding left child to vertex that not exists             //      200  
		//in the tree                                                 //     300 
		CHECK_THROWS(tree_of_ints.add_left(j , i));                  //    400 
        //adding left child to exists vertex 		                    //   500 
		CHECK_NOTHROW(tree_of_ints.add_left(i , j));		   //  600
	}
	
	 val = numOfVertices*100;
	// Check that all vertices have indeed been added to the tree  
	for(auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it){
		CHECK_EQ(*(it), val);
		val = val - 100;
	}
		
}


TEST_CASE("Test for the function add_right"){
	
	BinaryTree<double> tree_of_doubles;
	int numOfVertices  = 6; // num of Vertices in the tree
	
	// creating the root of the tree
	tree_of_doubles.add_root(0);
	
    // adding right childs                                                 // The tree:
	for(int i = 0; i < numOfVertices; i++){                           //   0
		int j = i + 1;                                           //      1
	    //try adding right child to vertex that not exists          //         2
		//in the tree                                          //            3
		CHECK_THROWS(tree_of_doubles.add_right(j , i));       //               4
		//adding right child to exists vertex                //                  5                    
		CHECK_NOTHROW(tree_of_doubles.add_right(i , j));    //                     6
	}                                                         
                                                              
	int val = numOfVertices;
	// Check that all vertices have indeed been added to the tree  
	for(auto it = tree_of_doubles.begin_postorder(); it != tree_of_doubles.end_postorder(); ++it){
		CHECK_EQ(*(it), val);
		val --;
	}
	
    /*
	Check that if a right child is added to a vertex 
	that already has a right child then the right child is updated to 
	the new right vertex                                       
	*/                                                                    //The new tree: 
	for(int i = 0; i < numOfVertices*100; i = i + 100){                  //   0  
		int j = i + 100;                                            //      100
		//try adding right child to vertex that not exists         //          200
		//in the tree                                             //              300
		CHECK_THROWS(tree_of_doubles.add_right(j , i));          //                  400
        //adding right child to exists vertex 		                //                      500
		CHECK_NOTHROW(tree_of_doubles.add_right(i , j));       //                          600
	}                                                        
                                                             
	 val = numOfVertices*100;
	// Check that all vertices have indeed been added to the tree  
	for(auto it = tree_of_doubles.begin_postorder(); it != tree_of_doubles.end_postorder(); ++it){
		cout << val << endl;
		CHECK_EQ(*(it), val);
		val = val - 100 ;
	}
		
}


TEST_CASE("Test for the Traversals - Unbalanced tree"){
    
	//creating unbalaced tree
	BinaryTree<char> unbalanced_tree;                  //The unbalanced tree:
	unbalanced_tree.add_root('a');                    //      a
	unbalanced_tree.add_left('a', 'b');              //     b
	unbalanced_tree.add_right('b', 'e');            //    d   e
	unbalanced_tree.add_left('b', 'd');
	
	int i;
	
	// inorder
	i = 0;
	char inorder[] = {'d', 'b', 'e', 'a'};
	
	for(auto it_in = unbalanced_tree.begin_inorder(); it_in != unbalanced_tree.end_inorder(); ++it_in){
		CHECK_EQ(*(it_in), inorder[i]);
		i++;
	}
	
	// preorder
	i = 0;
	char preorder[] = { 'a', 'b', 'd', 'e'}; 
	
	for(auto it_pre = unbalanced_tree.begin_preorder(); it_pre != unbalanced_tree.end_preorder(); ++it_pre){
		CHECK_EQ(*(it_pre), preorder[i]);
		i++;
	}
	
	// postorder
	i = 0;   
    char postorder[] = {'d', 'e', 'b', 'a'};
	for(auto it_post = unbalanced_tree.begin_postorder(); it_post != unbalanced_tree.end_postorder(); ++it_post){
		CHECK_EQ(*(it_post), postorder[i]);
		i++;
	}
	
}


TEST_CASE("Test for the Traversals - Balanced tree"){
    
	//creating balanced tree              //The balanced tree:
	BinaryTree<int> balanced_tree;       //        1
	balanced_tree.add_root(1);          //     2        3 
	balanced_tree.add_right(1, 3);     //    4   5    6   7
 	balanced_tree.add_left(1, 2);     //
	balanced_tree.add_right(2, 5);
	balanced_tree.add_left(2, 4);
	balanced_tree.add_right(3, 7);
	balanced_tree.add_left(3, 6);
	
	int i;
	
	// inorder
	i = 0;
	char inorder[] = {4, 2, 5, 1, 6, 3, 7};
	
	for(auto it_in = balanced_tree.begin_inorder(); it_in != balanced_tree.end_inorder(); ++it_in){
		CHECK_EQ(*(it_in), inorder[i]);
		i++;
	}
	
	// preorder
	i = 0;
	char preorder[] = { 1, 2, 4, 5, 3, 6, 7}; 
	
	for(auto it_pre = balanced_tree.begin_preorder(); it_pre != balanced_tree.end_preorder(); ++it_pre){
		CHECK_EQ(*(it_pre), preorder[i]);
		i++;
	}
	
	// postorder
	i = 0;   
    char postorder[] = {4, 5, 2, 6, 7, 3, 1};
	for(auto it_post = balanced_tree.begin_postorder(); it_post != balanced_tree.end_postorder(); ++it_post){
		CHECK_EQ(*(it_post), postorder[i]);
		i++;
	}
	
}


TEST_CASE("Test - big tree"){
	
	BinaryTree<int> big_tree;
	int numOfVertices = 50; // num of Vertices in the tree
	big_tree.add_root(100);
	for(int i = 0; i < numOfVertices; i++){
		/*
		Check that if there are several vertices with the same value 
		in the tree and we try to add a right/left vertex to it, no error is received but,
		the new vertex is added to one of these vertices 
		*/
		CHECK_NOTHROW(big_tree.add_left(100, 100));
		CHECK_NOTHROW(big_tree.add_right(100, 100));
		//adding right vertex and left vertex
		CHECK_THROWS(big_tree.add_right(i, i));
		CHECK_THROWS(big_tree.add_left(i, i));
	}
	
	//The three traversals are supposed to be the same 
	auto it_in = big_tree.begin_inorder();
	auto it_pre = big_tree.begin_preorder();
	auto it_post = big_tree.begin_postorder();
	for(int i = 0; i < numOfVertices; i++){
		CHECK(*(it_in) == 100);
		CHECK(*(it_pre) == 100);
		CHECK(*(it_post) == 100);
		it_in++;
		it_pre++;
		it_post++;
	}
}
		
	
		
		


	
	
	
	
	
	
	
