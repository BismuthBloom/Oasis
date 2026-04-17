//
// Created by Matthew McCall on 5/2/24.
//

#ifndef OASIS_SUMMATION_HPP
#define OASIS_SUMMATION_HPP

#include "BinaryExpression.hpp"

namespace Oasis {

// TODO: Doxygen description for summation

/**
 * The Integral expression integrates the two expressions together.
 *
 * @section param Parameters:
 * @tparam OperandT The type of the expression to be summed.
 * @tparam IncrementingVarT The variable to be incremented each step of the summation.
 * @tparam LowerBoundT The value the incrementing variable is initially equivalent to.
 * @tparam UpperBoundT The value the incrementing variable will be incremented towards.
 */
template <typename OperandT = Expression, typename IncrementingVarT = Expression>
class Summation : public BinaryExpression<Summation, OperandT, IncrementingVarT> {
public:
    Summation() = default;
    Summation(const Summation<OperandT, IncrementingVarT>& other) 
        : BinaryExpression<Summation, OperandT, IncrementingVarT>(other)
    {
        this->lowerBound = other.lowerBound.Copy();
        this->upperBound = other.upperBound.Copy();
    }

    Summation(const OperandT& operand, const IncrementingVarT& incrementingvar, const IncrementingVarT& lower, const IncrementingVarT& upper)
        : BinaryExpression<Summation, OperandT, IncrementingVarT>(operand, incrementingvar)
    {
        this->lowerBound = std::make_unique<IncrementingVarT>(lower);
        this->upperBound = std::make_unique<IncrementingVarT>(upper);
    }

    auto operator=(const Summation& other) -> Summation& = default;

private:
    std::unique_ptr<IncrementingVarT> lowerBound;
    std::unique_ptr<IncrementingVarT> upperBound;
};

} // Oasis

#endif // OASIS_SUMMATION_HPP
