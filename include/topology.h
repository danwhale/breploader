#ifndef TOPOLOGY_H_INCLUDED
#define TOPOLOGY_H_INCLUDED 1

#include "face.h"
#include "loop.h"
#include "edge.h"
#include "vertex.h"

#include <map>
#include <vector>
#include <memory>

namespace pspy {
struct TopologicalEntity {
    TopologicalEntity(int id, int entity_class) {
        _id = id;
        _entity_class = entity_class;
    }
    int _id;
    int _entity_class;
};

enum class TopoRelationSense
{
    None,
    Negative,
    Positive
};

struct TopoRelation {

    TopoRelation(int parent, int child, int sense) {
        _parent = parent;
        _child = child;
        _sense = TopoRelationSense::None;
    }

    int _parent;
    int _child;
    TopoRelationSense _sense;
};


struct BREPTopology {

    // Node Lists
    std::vector<std::shared_ptr<Face> > faces;
    std::vector<std::shared_ptr<Loop> > loops;
    std::vector<std::shared_ptr<Edge> > edges;
    std::vector<std::shared_ptr<Vertex> > vertices;

    // Edge Lists
    std::vector<TopoRelation> face_to_loop;
    std::vector<TopoRelation> loop_to_edge;
    std::vector<TopoRelation> edge_to_vertex;

    std::vector<TopoRelation> loop_to_vertex; // Degenerate Vertices

    // Meta-Path Edge List -- (face_id, face_id, edge_id)
    std::vector<std::tuple<size_t, size_t, size_t> > face_to_face;

    // Adjacency List Graph
    // Explicitly avoids degenerate vertices since
    // these should not be used as neighbors when
    // determining default MCFs
    std::map<int, std::vector<int> > face_loop;
    std::map<int, std::vector<int> > face_edge;
    std::map<int, std::vector<int> > face_vertex;
    std::map<int, std::vector<int> > loop_edge;
    std::map<int, std::vector<int> > loop_vertex;
    std::map<int, std::vector<int> > edge_vertex;
};

}

#endif // !TOPOLOGY_H_INCLUDED
