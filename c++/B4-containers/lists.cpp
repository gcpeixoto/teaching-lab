/* \file   lists.cpp
 * \author Gustavo Peixoto de Oliveira
 * \date   July, 2013 
 */

#include <iostream>
#include <vector>

using namespace std;

/* Study of lists. Doubly-linked lists and singly-linked lists. */

struct Link // entirely based on a "pointer game"
{
 	string value;
	Link* pred; // predecessor
	Link* succ; // successor
	Link(const string& v, Link* p = 0, Link* s = 0)
	 	: value(v), pred(p), succ(s) {} // constructor
}; 
/* That is, given a Link, we can get to its successor using the pointer
 * succ and to its predecessor using pred. Null pointer is to indicate
 * that a Link doesn't have a successor or a predecessor. */


/* Operations "under the covers" of the STL container List. */


/* ... | n | ----> p ----> ... 	*/
Link* insert(Link* p, Link* n) // insert n before p; return n
{
	if ( n == 0 ) return p; // not having nothing to insert, p remains
	if ( p == 0 ) return n; // not finding p, not insert n
	n->succ = p; // p comes after n
	n->pred = p->pred; // p's predecessor becomes n's predecessor
	p->pred = n; // n becomes p's predecessor
	return n;
}


/* ... ----> p ----> | n | ... */
Link* add(Link* p, Link* n) // insert n after p; return n
{
	if ( n == 0 ) return p;
	if ( p == 0 ) return n;
	n->pred = p; // p comes before n
	n->succ = p->succ;
	p->succ = n;
	return n;

}


/* ... pred ----> X | p | ----> succ ----> ... */  
Link* erase(Link* p) // remove *p from list; returns p's successor
{
	if ( p == 0 ) return 0; // null pointer, nothing to remove
	if ( p->succ ) p->succ->pred = p->pred; // if p has a successor 
	if ( p->pred ) p->pred->succ = p->succ; // if p has predecessor.
	// Two conditions above "confine" p in between
	return p->succ;

}


/* ... ----> pred ----> ? 's' ----> ? 's' ----> succ ... */
Link* find(Link* p, const string& s) // find s in list; return 0 for "not found"
{
 	while(p) // iterates until find string
	{
	 	if ( p->value == s ) return p;
		p = p->succ;
	}

	return 0;
}
	

Link* advance(Link* p, int n) // move n positions in list; // return 0 for "not found"
{
	// positive n moves forward, negative backward
	
 	if ( p == 0 ) return 0;
	if ( n > 0 ) 
	{
	 	while(n--)
		{
		 	if ( p->succ == 0 ) return 0;
			p = p->succ;
		}
	}
	if ( n < 0 ) 
	{
	 	while(n++)
		{
		 	if ( p->pred == 0 ) return 0;
			p = p->pred;
		}
	}

	return p;
}

int main(int argc, char* argv[])
{
	/* Building a list of fruits by links 
	 *
	 * lemon ----> banana ----> apple 
	 *
	 * Firstly, created apple, then banana as pred. of apple, and
	 * finally lemon as pred. of banana. */
	Link* fruits = new Link("apple",0,0);
	fruits = new Link("banana",fruits,0);
	fruits->succ->pred = fruits;
	fruits = new Link("lemon",fruits,0);
	fruits->succ->pred = fruits;

 	
}	
