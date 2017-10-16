/**
 * A framework to implement a first-child, right-sibling
 * tree with arbitrary children per node.
 * @author Original Author Jon Beck
 * @author Modified By Your Name Here
 * @version date last modified
 */

#include <iostream>
using namespace std;

/**
 * a tree_node class
 */
class Tree_Node
{
public:
  //What does this mean???
    Tree_Node( char data, Tree_Node * first_child, Tree_Node * right_sibling )
    : data( data ), first_child( first_child ), right_sibling( right_sibling )
  {}
  char get_data() const
  {
    return data;
  }

  Tree_Node * get_first_child() const
  {
    return first_child;
  }

  Tree_Node * get_right_sibling() const
  {
    return right_sibling;
  }


private:
  char data;
  Tree_Node * first_child;
  Tree_Node * right_sibling;
};

void visit( Tree_Node * node )
{
  cout << node->get_data() << ' ';
}

void preorder( Tree_Node * node )
{
  if( node != nullptr )
  {
    visit( node );
    preorder( node->get_first_child() );
    preorder( node->get_right_sibling() );
  }
}

void postorder( Tree_Node * node )
{
  if(node != nullptr )
  {
    postorder( node-> get_first_child() );
    postorder( node-> get_right_sibling() );
    visit( node );
  }
}

void inorder( Tree_Node * node )
{
  if( node != nullptr )
  {
    inorder( node -> get_first_child() );
    visit( node );
    inorder( node -> get_right_sibling() );
  }
}

int main()
{
  Tree_Node * q = new Tree_Node{ 'Q', nullptr, nullptr };
  Tree_Node * p = new Tree_Node{ 'P', nullptr, q };
  Tree_Node * o = new Tree_Node{ 'O', nullptr, p };
  Tree_Node * n = new Tree_Node{ 'N', nullptr, nullptr };
  Tree_Node * m = new Tree_Node{ 'M', nullptr, n };
  Tree_Node * l = new Tree_Node{ 'L', nullptr, nullptr };
  Tree_Node * k = new Tree_Node{ 'K', nullptr, l };
  Tree_Node * j = new Tree_Node{ 'J', nullptr, k };
  Tree_Node * i = new Tree_Node{ 'I', o, nullptr };
  Tree_Node * h = new Tree_Node{ 'H', nullptr, i };
  Tree_Node * g = new Tree_Node{ 'G', nullptr, h };
  Tree_Node * f = new Tree_Node{ 'F', m, nullptr };
  Tree_Node * e = new Tree_Node{ 'E', j, nullptr };
  Tree_Node * d = new Tree_Node{ 'D', g, e };
  Tree_Node * c = new Tree_Node{ 'C', nullptr, d };
  Tree_Node * b = new Tree_Node{ 'B', f, c };
  Tree_Node * a = new Tree_Node{ 'A', b, nullptr };

  cout << "Preorder: ";
  preorder( a );
  cout << endl;

  cout << "Postorder: ";
  postorder( a );
  cout << endl;

  cout <<"Inorder: ";
  inorder( a );
  cout << endl;

  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
  delete f;
  delete g;
  delete h;
  delete i;
  delete j;
  delete k;
  delete l;
  delete m;
  delete n;
  delete o;
  delete p;
  delete q;
  return 0;
}