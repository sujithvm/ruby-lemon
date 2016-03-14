#include "_lemon_list_graph.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Lemon
#include <lemon/core.h>
#include <lemon/list_graph.h>

using namespace lemon;
using namespace Rice;

namespace {
    // ListGraph
    int ListGraph_countNodes(ListGraph const & self) {
    	return countNodes(self);
    }
    int ListGraph_countEdges(ListGraph const & self) {
        return countEdges(self);
    }
    int ListGraph_countArcs(ListGraph const & self) {
        return countArcs(self);
    }

    // ListDigraph
    int ListDigraph_countNodes(ListDigraph const & self) {
        return countNodes(self);
    }
    int ListDigraph_countArcs(ListDigraph const & self) {
        return countArcs(self);
    } 
    int ListDigraph_nodeId(ListDigraphBase::Node const & node) {
        return ListDigraphBase::id(node);
    }       
}

void register_list_graph(Rice::Module rb_mlemon) {

    // lemon::ListGraph

    // ListGraphBase
    define_class_under< ListGraphBase >(rb_mlemon, "ListGraphBase")
        .define_constructor(Constructor< ListGraphBase >());        
    // ListGraphBase::Node
    define_class_under< ListGraphBase::Node >(rb_mlemon, "Node")
        .define_constructor(Constructor< ListGraphBase::Node >());
    // ListGraphBase::Edge
    define_class_under< ListGraphBase::Edge >(rb_mlemon, "Edge")
        .define_constructor(Constructor< ListGraphBase::Edge >());
    // ListGraphBase::Arc
    define_class_under< ListGraphBase::Arc >(rb_mlemon, "Arc")
        .define_constructor(Constructor< ListGraphBase::Arc >());
    
    
    typedef void (ListGraph::*erase_lg_node)(ListGraphBase::Node);
    typedef void (ListGraph::*erase_lg_edge)(ListGraphBase::Edge);
   
    define_class_under< ListGraph, ListGraphBase >(rb_mlemon, "ListGraph")    
        .define_constructor(Constructor< ListGraph >())        
        .define_method("add_node", &ListGraph::addNode)
        .define_method("add_edge", &ListGraph::addEdge)
        .define_method("erase_node", erase_lg_node(&ListGraph::erase))
        .define_method("erase_edge", erase_lg_edge(&ListGraph::erase))
        .define_method("change_u", &ListGraph::changeU)
        .define_method("change_v", &ListGraph::changeV)
        .define_method("clear", &ListGraph::clear)
        .define_method("node_count", ListGraph_countNodes)
        .define_method("edge_count", ListGraph_countEdges)
        .define_method("arc_count", ListGraph_countArcs)
        ;




    // lemon::ListDigraph

   
    // Node
    define_class_under< ListDigraphBase::Node >(rb_mlemon, "Node")
        .define_constructor(Constructor< ListDigraphBase::Node >());    
    // Arc
    define_class_under< ListDigraphBase::Arc >(rb_mlemon, "Arc")
        .define_constructor(Constructor< ListDigraphBase::Arc >()); 

    typedef int (ListDigraphBase::*ldg_node_id)(ListDigraphBase::Node);    
    // ListDigraphBase
    define_class_under< ListDigraphBase >(rb_mlemon, "ListDigraphBase")
        .define_constructor(Constructor< ListDigraphBase >())
        .define_method("node_id", ListDigraph_nodeId)      
        ;        
    

    typedef void (ListDigraph::*erase_ldg_node)(ListDigraphBase::Node);
    typedef void (ListDigraph::*erase_ldg_arc)(ListDigraphBase::Arc);    

    

    define_class_under< ListDigraph, ListDigraphBase >(rb_mlemon, "ListDigraph")
        .define_constructor(Constructor< ListDigraph >())        
        .define_method("add_node", &ListDigraph::addNode)
        .define_method("add_arc", &ListDigraph::addArc)
        .define_method("erase_node", erase_ldg_node(&ListDigraph::erase))
        .define_method("erase_arc", erase_ldg_arc(&ListDigraph::erase))      
        .define_method("change_target", &ListDigraph::changeTarget)
        .define_method("change_source", &ListDigraph::changeSource )
        .define_method("reverse_arc", &ListDigraph::reverseArc)
        .define_method("clear", &ListDigraph::clear)
        .define_method("node_count", ListDigraph_countNodes)
        .define_method("arc_count", ListDigraph_countArcs)
        
        ;    
}
