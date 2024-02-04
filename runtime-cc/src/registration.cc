#include "registration.h"

#include "../leetcode-cc/BTreeLevelTraversalII.hpp"
#include "../leetcode-cc/BTreeZigzagLevelOrderTraversal.hpp"
#include "../leetcode-cc/BalancedBTree.hpp"
#include "../leetcode-cc/BinaryTreeInorderTraversal.hpp"
#include "../leetcode-cc/BinaryTreeLevelOrderTraversal.hpp"
#include "../leetcode-cc/ConstructBTreeInorderPostorder.hpp"
#include "../leetcode-cc/ConstructBTreePreorderInorder.hpp"
#include "../leetcode-cc/ConvertSortedArrayToBST.hpp"
#include "../leetcode-cc/ConvertSortedListToBST.hpp"
#include "../leetcode-cc/DecodeWays.hpp"
#include "../leetcode-cc/DetIfTwoStrsAreClose.hpp"
#include "../leetcode-cc/DeterIfStringHalvesAreAlike.hpp"
#include "../leetcode-cc/DistinctSubsequences.hpp"
#include "../leetcode-cc/DivideTwoIntegers.hpp"
#include "../leetcode-cc/FindPlayersWithZeroOrOneLosses.hpp"
#include "../leetcode-cc/FlattenBTreeToLinkedList.hpp"
#include "../leetcode-cc/FourSum.hpp"
#include "../leetcode-cc/GenerateParentheses.hpp"
#include "../leetcode-cc/GrayCode.hpp"
#include "../leetcode-cc/HouseRobber.hpp"
#include "../leetcode-cc/InsertDeleteGetrandomO1.hpp"
#include "../leetcode-cc/IntegerToRoman.hpp"
#include "../leetcode-cc/InterleavingString.hpp"
#include "../leetcode-cc/KInversePairsArray.hpp"
#include "../leetcode-cc/LargestRectangleInHistogram.hpp"
#include "../leetcode-cc/LetterCombsOfAPhoneNum.hpp"
#include "../leetcode-cc/LongestCommonPrefix.hpp"
#include "../leetcode-cc/LongestCommonSubsequence.hpp"
#include "../leetcode-cc/MaxDepthOfBTree.hpp"
#include "../leetcode-cc/MaxDiffBetNodeAndAncestor.hpp"
#include "../leetcode-cc/MaxLenOfConcatenatedStrWithUniqueChars.hpp"
#include "../leetcode-cc/MaximalRectangle.hpp"
#include "../leetcode-cc/MergeKSortedLists.hpp"
#include "../leetcode-cc/MergeSortedArray.hpp"
#include "../leetcode-cc/MergeTwoSortedLists.hpp"
#include "../leetcode-cc/MinDepthOfBTree.hpp"
#include "../leetcode-cc/MinFallingPathSum.hpp"
#include "../leetcode-cc/MinNumStepsMakeTwoStrAnagram.hpp"
#include "../leetcode-cc/NextPermutation.hpp"
#include "../leetcode-cc/OutOfBoundaryPaths.hpp"
#include "../leetcode-cc/PartitionList.hpp"
#include "../leetcode-cc/PascalsTriangle.hpp"
#include "../leetcode-cc/PascalsTriangleII.hpp"
#include "../leetcode-cc/PathSum.hpp"
#include "../leetcode-cc/PathSumII.hpp"
#include "../leetcode-cc/PopulateNextRightPointers.hpp"
#include "../leetcode-cc/PseudoPalindromicPathsInBTree.hpp"
#include "../leetcode-cc/RecoverBST.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedList.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedListII.hpp"
#include "../leetcode-cc/RemoveElement.hpp"
#include "../leetcode-cc/RemoveNthNode.hpp"
#include "../leetcode-cc/RestoreIpAddresses.hpp"
#include "../leetcode-cc/ReverseLinkedListII.hpp"
#include "../leetcode-cc/ReverseNodesinKGroup.hpp"
#include "../leetcode-cc/RomanToInteger.hpp"
#include "../leetcode-cc/SameTree.hpp"
#include "../leetcode-cc/ScrambleString.hpp"
#include "../leetcode-cc/SearchInRotaedSortedArray.hpp"
#include "../leetcode-cc/SetMismatch.hpp"
#include "../leetcode-cc/SubsetsII.hpp"
#include "../leetcode-cc/SumOfSubArrayMin.hpp"
#include "../leetcode-cc/SymmetricTree.hpp"
#include "../leetcode-cc/ThreeSum.hpp"
#include "../leetcode-cc/ThreeSumClosest.hpp"
#include "../leetcode-cc/Triangle.hpp"
#include "../leetcode-cc/UniqueBinarySearchTrees.hpp"
#include "../leetcode-cc/UniqueBinarySearchTreesII.hpp"
#include "../leetcode-cc/UniqueNumOfOccurrences.hpp"
#include "../leetcode-cc/ValidParentheses.hpp"
#include "../leetcode-cc/ValidateBST.hpp"

const int registerAll(std::shared_ptr<Container> handle) {
  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PIntToRoman>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SIntToRoman>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRomanToInt>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRomanToInt>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PLongestCommonPrefix>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SLonestCommonPrefix>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PThreeSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SThreeSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PThreeSumClosest>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SThreeSumClosest>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PLetterCombsOfAPhoneNum>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SLetterCombsOfAPhoneNum>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PFourSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SFourSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRemoveNthNode>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRemoveNthNode>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PValidParentheses>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SValidParentheses>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMergeTwoSortedLists>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMergeTwoSortedLists>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PGenerateParentheses>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SGenerateParentheses>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMergeKSortedLists>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMergeKSortedLists>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReverseNodesInKGroup>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SReverseNodesInKGroup>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRemoveElement>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRemoveElement>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PDivideTwoIntegers>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SDivideTwoIntegers>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PNextPermutation>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SNextPermutation>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PSearchInRotatedSortedArray>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SSearchInRotatedSortedArray>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PRemoveDuplicatesFromSortedList>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SRemoveDuplicatesFromSortedList>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PRemoveDuplicatesFromSortedListII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SRemoveDuplicatesFromSortedListII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMergeSortedArray>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMergeSortedArray>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PPartitionList>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SPartitionList>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PLargestRectangleInHistogram>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SLargestRectangleInHistogram>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMaximalRectangle>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMaximalRectangle>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PGrayCode>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SGrayCode>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PScrambleString>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SScrambleString>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSubsetsII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSubsetsII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PDecodeWays>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SDecodeWays>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReverseLinkedListII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SReverseLinkedListII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRestoreIPAddresses>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRestoreIPAddresses>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreeInorderTraversal>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreeInorderTraversal>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PUqBinarySearchTrees>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SUqBinarySearchTrees>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PUqBinarySearchTreesII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SUqBinarySearchTreesII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PInterleavingString>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SInterleavingString>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PValidateBST>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SValidateBST>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRecoverBST>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRecoverBST>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSameTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSameTree>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PMaxDiffBetNodeAndAncestor>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SMaxDiffBetNodeAndAncestor>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PDeterIfStringHalvesAlike>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SDeterIfStringHalvesAlike>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSymmetricTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSymmetricTree>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PMinNumStepsMakeTwoStrAnagram>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SMinNumStepsMakeTwoStrAnagram>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PDetIfTwoStrsAreClose>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SDetIfTwoStrsAreClose>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreeLevelOrderTraversal>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreeLevelOrderTraversal>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PFindPlayersWithZeroOrOneLosses>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SFindPlayersWithZeroOrOneLosses>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PInsertDeleteGetrandO1>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SInsertDeleteGetrandO1>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PUniqueNumOfOccurrences>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SUniqueNumOfOccurrences>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreeZigzagLevelOrderTraversal>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreeZigzagLevelOrderTraversal>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMinFallingPathSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMinFallingPathSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSumOfSubArrayMin>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSumOfSubArrayMin>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSetMisMatch>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSetMisMatch>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PMaxLenOfConcatenatedStrWithUniqueChars>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SMaxLenOfConcatenatedStrWithUniqueChars>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PHouseRobber>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SHouseRobber>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PPseudoPalindromicPathsInBTree>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SPseudoPalindromicPathsInBTree>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PLongestCommonSubsequence>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SLongestCommonSubsequence>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMaxDepthOfBTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMaxDepthOfBTree>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PConstructBTreePreorderInorder>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SConstructBTreePreorderInorder>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<POutOfBoundaryPaths>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SOutOfBoundaryPaths>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PKInversePairsArray>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SKInversePairsArray>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PConstructBTreeInorderPostorder>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SConstructBTreeInorderPostorder>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreeLevelTraversalII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreeLevelTraversalII>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PConvertSortedArrayToBST>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SConvertSortedArrayToBST>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PConvertSortedListToBST>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SConvertSortedListToBST>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PBalancedBTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SBalancedBTree>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMinDepthOfBTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMinDepthOfBTree>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PPathSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SPathSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PPathSumII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SPathSumII>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PFlattenBTreeToLinkedList>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SFlattenBTreeToLinkedList>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PDistinctSubsequences>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SDistinctSubsequences>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PPopulateNextRightPointers>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SPopulateNextRightPointers>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PPascalsTriangle>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SPascalsTriangle>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PPascalsTriangleII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SPascalsTriangleII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PTriangle>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<STriangle>(); });

  return 0;
}
