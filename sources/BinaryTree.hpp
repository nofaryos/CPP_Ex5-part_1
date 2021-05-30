#pragma once



namespace ariel{
	template<typename T>
	class BinaryTree{
		public:
			BinaryTree(){};
			~BinaryTree(){};
			BinaryTree& add_root(T new_root){this -> root = new Node(new_root);
			return *this;}
			BinaryTree& add_left(T exsist_node, T left_childNode){return *this;}
			BinaryTree& add_right(T exsist_node, T right_childNnode){return *this;}
			friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& tree){return os;}
		private:
			struct Node {
				T data;
				Node* right;
				Node* left;
				Node(T data){
					this->data = data;
					right = left = NULL;
				}
		};
		
			Node* root;
		public:	
			class iterator{

				private:
					Node* pointer_to_current_node;

				public:

					iterator(Node* ptr = nullptr)
					: pointer_to_current_node(ptr) {
					};

					T& operator*() const {return pointer_to_current_node->data;}

					iterator& operator++() {return *this;}

					//postfix
					const iterator operator++(int){return *this;}
						
					bool operator==(const iterator& rhs) const {
						return false;
					}

					bool operator!=(const iterator& rhs) const {
						return false;
					}
					
					T* operator->() const {
						return &(pointer_to_current_node->data);
					}
					
					
			};  // END OF CLASS ITERATOR
			
			class const_iterator {

				private:
						Node* pointer_to_current_node;

				public:
					const_iterator(Node* ptr = nullptr)
					: pointer_to_current_node(ptr) {
					}

					const T& operator*() const {
						return pointer_to_current_node->data;
					}

					// ++i;
					const_iterator& operator++() {return *this;}

					// i++;
					// Usually iterators are passed by value and not by const& as they are small.
					const const_iterator operator++(int){return *this;}
						
					bool operator==(const const_iterator& rhs) const {
						return pointer_to_current_node == rhs.pointer_to_current_node;
					}

					bool operator!=(const const_iterator& rhs) const {
						return pointer_to_current_node != rhs.pointer_to_current_node;
					}
					
					const T* operator->() const {
						return &(pointer_to_current_node->data);
					}
			};  // END OF CLASS const_iterator
			
			
			iterator begin_preorder() {
			// return &(m_first->m_value); 
				return iterator{root};
			}
		
			iterator end_preorder() {
				// return nullptr; 
				return iterator{nullptr};
			}
			
			iterator begin_inorder() {
			// return &(m_first->m_value); 
				return iterator{root};
			}
			
			iterator end_inorder() {
				// return nullptr; 
				return iterator{nullptr};
			}
			
			iterator begin_postorder() {
			// return &(m_first->m_value); 
				return iterator{root};
			}
			
			iterator end_postorder() {
				// return nullptr; 
				return iterator{nullptr};
			}

			const_iterator cbegin() const {
				return const_iterator{root};
			}
		
			const_iterator cend() const {
				return const_iterator{nullptr};
			}
		
			iterator begin()  {
				return iterator{root};
			}
		
			iterator end()  {
				return iterator{nullptr};
			}
			
			
	};
	
	
}
