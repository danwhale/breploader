#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED 1

#include <Eigen/Core>
#include <vector>
#include <TopoDS_Vertex.hxx>
#include "types.h"

namespace pspy {

struct Vertex {
    Eigen::Vector3d position;
    std::string export_id;

    virtual std::vector<Inference> get_inferences() = 0;

};

struct OCCTVertex: public Vertex {
    OCCTVertex(const TopoDS_Shape& shape);

    TopoDS_Vertex _shape;

    std::vector<Inference> get_inferences() override;
};

}

#endif // !VERTEX_H_INCLUDED
