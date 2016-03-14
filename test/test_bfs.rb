require "test/unit"
require File.expand_path('../../lib/ruby_lemon', __FILE__)

class TestBfs < Test::Unit::TestCase

  def test_bfs
  	graph = Lemon::ListDigraph.new
  	n1, n2, n3, n4 = graph.add_node(), graph.add_node(), graph.add_node(), graph.add_node()   
  	graph.add_arc(n2, n1);
  	graph.add_arc(n3, n2);
  	graph.add_arc(n3, n4);

  	bfs = Lemon::Bfs.create(graph)
    bfs.init()
    bfs.add_source(n3)

    assert_equal(1, bfs.queue_size)
    assert_equal(false, bfs.empty_queue)

    nn = bfs.process_next_node();

    assert_equal(2, bfs.queue_size)
    assert_equal(false, bfs.empty_queue)

    nn = bfs.process_next_node();

    assert_equal(1, bfs.queue_size)
    assert_equal(false, bfs.empty_queue)

    nn = bfs.process_next_node();

    assert_equal(1, bfs.queue_size)
    assert_equal(false, bfs.empty_queue)

    nn = bfs.process_next_node();

    assert_equal(0, bfs.queue_size)
    assert_equal(true, bfs.empty_queue)

       
  end  

end
