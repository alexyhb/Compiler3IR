// #include "program.h"

// // Program::Program(const Node *program_node) {
// //   this->program_node = program_node;
// //   for (const auto &child : this->entry_point) {
// //         if (child->getType() == "VarDeclaration") {
// //             child->generateST();
// //         }
// //     }
//   // for (const auto &class_node : program_node->declarations) {
//   //   if (class_node->internal)
//   //     continue;

//   //   // for (const auto &method_declaration_node : class_node->method_declarations) {
//   //   //   ControlFlowGraph *cfg = new ControlFlowGraph();
//   //   //   // generate_method_ir(cfg, class_node, method_declaration_node);
//   //   //   this->cfgs[class_node->identifier + "." + method_declaration_node->identifier] = cfg;
//   //   //   if (method_declaration_node->identifier.compare("main") == 0)
//   //   //     this->entry_point = cfg;
//   //   // }
//   // }

// //}

// void Program::write_cfg(std::ostream &stream) const {
//   stream << "digraph {" << std::endl;
//   stream << "graph [splines=ortho]" << std::endl;
//   stream << "compound=true;" << std::endl;

//   for (const auto &[key, cfg] : this->cfgs) {
//     if (cfg == this->entry_point) {
//       stream << "entrypoint[shape=box label=\"Entry Point\"];" << std::endl;
//       stream << "entrypoint -> " << cfg->entry_point->get_id() << ";" << std::endl;
//     }
//     stream << "subgraph \"cluster" << key << "\" {" << std::endl;
//     stream << "label = \"" << key << "\";" << std::endl;
//     cfg->write(stream);
//     stream << "}" << std::endl;
//   }

//   stream << "}" << std::endl;
// }