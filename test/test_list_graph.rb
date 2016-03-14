require "test/unit"
require File.expand_path('../../lib/ruby_lemon', __FILE__)

class TestListGraph < Test::Unit::TestCase

  def test_nodes
    graph = Lemon::ListGraph.new

    n1, n2, n3 = graph.add_node(), graph.add_node(), graph.add_node()   

    assert_equal(graph.node_count() , 3)

    graph.erase_node(n2)
    assert_equal(graph.node_count(), 2)

    graph.erase_node(n1)
    assert_equal(graph.node_count(), 1)

    graph.erase_node(n3)
    assert_equal(graph.node_count(), 0)

    graph.clear()
    assert_equal(graph.node_count(), 0)
  end 

  def test_edges
    graph = Lemon::ListGraph.new

    n1, n2, n3, n4 = graph.add_node(), graph.add_node(), graph.add_node(), graph.add_node()  
    e1 = graph.add_edge(n1, n2)
    e2 = graph.add_edge(n3, n4)
    
    assert_equal(graph.edge_count(), 2)

    graph.erase_node(n3)
    assert_equal(graph.edge_count(), 1)

    graph.erase_edge(e1)
    assert_equal(graph.edge_count(), 0)
  end 

  def test_list_di_graph
    graph = Lemon::ListDigraph.new

    n1, n2, n3, n4 = graph.add_node(), graph.add_node(), graph.add_node(), graph.add_node() 
    a1 = graph.add_arc(n1, n3) 
    a2 = graph.add_arc(n2, n4)

    assert_equal(graph.node_count(), 4)
    assert_equal(graph.arc_count(), 2)

    graph.clear()

    assert_equal(graph.node_count(), 0)
    assert_equal(graph.arc_count(), 0)
  end 

end
