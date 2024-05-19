#pragma once

#include <IO/Operators.h>
#include <Processors/IProcessor.h>

namespace DB
{

using Statuses = std::vector<IProcessor::Status>;
/** Print pipeline in "dot" format for GraphViz.
  * You can render it with:
  *  dot -T png < pipeline.dot > pipeline.png
  */
void printPipeline(const Processors & processors, const Statuses  & statuses, WriteBuffer & out, bool print_stats=false);

void printPipeline(const Processors & processors, WriteBuffer & out, bool print_stats = false);

/// Prints pipeline in compact representation.
/// Group processors by it's name, QueryPlanStep and QueryPlanStepGroup.
/// If QueryPlanStep wasn't set for processor, representation may be not correct.
/// If with_header is set, prints block header for each edge.
void printPipelineCompact(const Processors & processors, WriteBuffer & out, bool with_header);
}
