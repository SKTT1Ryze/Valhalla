#include "registration.h"

#include "../leetcode-cc/BSTIterator.hpp"
#include "../leetcode-cc/BTRightSideView.hpp"
#include "../leetcode-cc/BTreeLevelTraversalII.hpp"
#include "../leetcode-cc/BTreeMaxPathSum.hpp"
#include "../leetcode-cc/BTreePostorderTraversal.hpp"
#include "../leetcode-cc/BTreePreorderTraversal.hpp"
#include "../leetcode-cc/BTreeZigzagLevelOrderTraversal.hpp"
#include "../leetcode-cc/BalancedBTree.hpp"
#include "../leetcode-cc/BestTimeToBuySellStockIII.hpp"
#include "../leetcode-cc/BestTimeToBuySellStockIV.hpp"
#include "../leetcode-cc/BinaryTreeInorderTraversal.hpp"
#include "../leetcode-cc/BinaryTreeLevelOrderTraversal.hpp"
#include "../leetcode-cc/BitWiseANDOfNumRange.hpp"
#include "../leetcode-cc/CloneGraph.hpp"
#include "../leetcode-cc/CmpVersionNum.hpp"
#include "../leetcode-cc/ConstructBTreeInorderPostorder.hpp"
#include "../leetcode-cc/ConstructBTreePreorderInorder.hpp"
#include "../leetcode-cc/ContainsDuplicateIII.hpp"
#include "../leetcode-cc/ConvertSortedArrayToBST.hpp"
#include "../leetcode-cc/ConvertSortedListToBST.hpp"
#include "../leetcode-cc/CopyListWithRandPointer.hpp"
#include "../leetcode-cc/CountPrimes.hpp"
#include "../leetcode-cc/CourseSchedule.hpp"
#include "../leetcode-cc/CourseScheduleII.hpp"
#include "../leetcode-cc/DecodeWays.hpp"
#include "../leetcode-cc/DetIfTwoStrsAreClose.hpp"
#include "../leetcode-cc/DeterIfStringHalvesAreAlike.hpp"
#include "../leetcode-cc/DistinctSubsequences.hpp"
#include "../leetcode-cc/DivideTwoIntegers.hpp"
#include "../leetcode-cc/DungeonGame.hpp"
#include "../leetcode-cc/EvaluateReversePolishNotation.hpp"
#include "../leetcode-cc/ExcelSheetColNum.hpp"
#include "../leetcode-cc/ExcelSheetColTitle.hpp"
#include "../leetcode-cc/FactorialTrailingZeroes.hpp"
#include "../leetcode-cc/FindMinInRotatedSortedArray.hpp"
#include "../leetcode-cc/FindMinInRotatedSortedArrayII.hpp"
#include "../leetcode-cc/FindPeakElement.hpp"
#include "../leetcode-cc/FindPlayersWithZeroOrOneLosses.hpp"
#include "../leetcode-cc/FlattenBTreeToLinkedList.hpp"
#include "../leetcode-cc/FourSum.hpp"
#include "../leetcode-cc/FractionToDecimal.hpp"
#include "../leetcode-cc/GenerateParentheses.hpp"
#include "../leetcode-cc/GrayCode.hpp"
#include "../leetcode-cc/HappyNumber.hpp"
#include "../leetcode-cc/HouseRobber.hpp"
#include "../leetcode-cc/ImplStackUsingQueues.hpp"
#include "../leetcode-cc/ImplTriePrefixTree.hpp"
#include "../leetcode-cc/InsertDeleteGetrandomO1.hpp"
#include "../leetcode-cc/InsertionSortList.hpp"
#include "../leetcode-cc/IntegerToRoman.hpp"
#include "../leetcode-cc/InterleavingString.hpp"
#include "../leetcode-cc/IntersectionOfTwoLL.hpp"
#include "../leetcode-cc/IsomorphicStrings.hpp"
#include "../leetcode-cc/KInversePairsArray.hpp"
#include "../leetcode-cc/KthLargestElement.hpp"
#include "../leetcode-cc/LargestRectangleInHistogram.hpp"
#include "../leetcode-cc/LetterCombsOfAPhoneNum.hpp"
#include "../leetcode-cc/LinkedListCycle.hpp"
#include "../leetcode-cc/LinkedListCycleII.hpp"
#include "../leetcode-cc/LongestCommonPrefix.hpp"
#include "../leetcode-cc/LongestCommonSubsequence.hpp"
#include "../leetcode-cc/LongestConsecutiveSeq.hpp"
#include "../leetcode-cc/LruCache.hpp"
#include "../leetcode-cc/MajorityElement.hpp"
#include "../leetcode-cc/MaxDepthOfBTree.hpp"
#include "../leetcode-cc/MaxDiffBetNodeAndAncestor.hpp"
#include "../leetcode-cc/MaxGap.hpp"
#include "../leetcode-cc/MaxLenOfConcatenatedStrWithUniqueChars.hpp"
#include "../leetcode-cc/MaxPoints.hpp"
#include "../leetcode-cc/MaxProductSubarray.hpp"
#include "../leetcode-cc/MaximalRectangle.hpp"
#include "../leetcode-cc/MergeKSortedLists.hpp"
#include "../leetcode-cc/MergeSortedArray.hpp"
#include "../leetcode-cc/MergeTwoSortedLists.hpp"
#include "../leetcode-cc/MinDepthOfBTree.hpp"
#include "../leetcode-cc/MinFallingPathSum.hpp"
#include "../leetcode-cc/MinNumStepsMakeTwoStrAnagram.hpp"
#include "../leetcode-cc/MinSizeSubarraySum.hpp"
#include "../leetcode-cc/MinStack.hpp"
#include "../leetcode-cc/NextPermutation.hpp"
#include "../leetcode-cc/NumOfIslands.hpp"
#include "../leetcode-cc/NumOfOneBits.hpp"
#include "../leetcode-cc/OutOfBoundaryPaths.hpp"
#include "../leetcode-cc/PalindromePartitioning.hpp"
#include "../leetcode-cc/PalindromePartitioningII.hpp"
#include "../leetcode-cc/PartitionList.hpp"
#include "../leetcode-cc/PascalsTriangle.hpp"
#include "../leetcode-cc/PascalsTriangleII.hpp"
#include "../leetcode-cc/PathSum.hpp"
#include "../leetcode-cc/PathSumII.hpp"
#include "../leetcode-cc/PopulateNextRightPointers.hpp"
#include "../leetcode-cc/PseudoPalindromicPathsInBTree.hpp"
#include "../leetcode-cc/RecoverBST.hpp"
#include "../leetcode-cc/RectangleArea.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedList.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedListII.hpp"
#include "../leetcode-cc/RemoveElement.hpp"
#include "../leetcode-cc/RemoveLinkedListElements.hpp"
#include "../leetcode-cc/RemoveNthNode.hpp"
#include "../leetcode-cc/ReorderList.hpp"
#include "../leetcode-cc/RepeatedDNASeq.hpp"
#include "../leetcode-cc/RestoreIpAddresses.hpp"
#include "../leetcode-cc/ReverseBits.hpp"
#include "../leetcode-cc/ReverseLinkedList.hpp"
#include "../leetcode-cc/ReverseLinkedListII.hpp"
#include "../leetcode-cc/ReverseNodesinKGroup.hpp"
#include "../leetcode-cc/ReverseWords.hpp"
#include "../leetcode-cc/RomanToInteger.hpp"
#include "../leetcode-cc/RotateArray.hpp"
#include "../leetcode-cc/SameTree.hpp"
#include "../leetcode-cc/ScrambleString.hpp"
#include "../leetcode-cc/SearchInRotaedSortedArray.hpp"
#include "../leetcode-cc/SetMismatch.hpp"
#include "../leetcode-cc/ShortestPalindrome.hpp"
#include "../leetcode-cc/SingleNumber.hpp"
#include "../leetcode-cc/SingleNumberII.hpp"
#include "../leetcode-cc/SortList.hpp"
#include "../leetcode-cc/SubsetsII.hpp"
#include "../leetcode-cc/SumOfSubArrayMin.hpp"
#include "../leetcode-cc/SumRootToLeafNums.hpp"
#include "../leetcode-cc/SurroundedRegions.hpp"
#include "../leetcode-cc/SymmetricTree.hpp"
#include "../leetcode-cc/TheSkylineProblem.hpp"
#include "../leetcode-cc/ThreeSum.hpp"
#include "../leetcode-cc/ThreeSumClosest.hpp"
#include "../leetcode-cc/Triangle.hpp"
#include "../leetcode-cc/TwoSumIIInputArraySorted.hpp"
#include "../leetcode-cc/UglyNumberII.hpp"
#include "../leetcode-cc/UniqueBinarySearchTrees.hpp"
#include "../leetcode-cc/UniqueBinarySearchTreesII.hpp"
#include "../leetcode-cc/UniqueNumOfOccurrences.hpp"
#include "../leetcode-cc/ValidPalindrome.hpp"
#include "../leetcode-cc/ValidParentheses.hpp"
#include "../leetcode-cc/ValidateBST.hpp"
#include "../leetcode-cc/WordBreak.hpp"
#include "../leetcode-cc/WordBreakII.hpp"
#include "../leetcode-cc/WordLadder.hpp"
#include "../leetcode-cc/WordLadderII.hpp"
#include "../leetcode-cc/WordSearchII.hpp"
#include "../leetcode-cc/WordsDataStructure.hpp"

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

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PValidPalindrome>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SValidPalindrome>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PLongestConsecutiveSeq>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SLongestConsecutiveSeq>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBestTimeToBuySellStockIII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBestTimeToBuySellStockIII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PBTreeMaxPathSum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SBTreeMaxPathSum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordLadder>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordLadder>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordLadderII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordLadderII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSumRootToLeafNums>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSumRootToLeafNums>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSurroundedRegions>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSurroundedRegions>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PPalindromePartitioning>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SPalindromePartitioning>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PPalindromePartitioningII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SPalindromePartitioningII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PCloneGraph>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SCloneGraph>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSingleNumber>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSingleNumber>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSingleNumberII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSingleNumberII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordBreak>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordBreak>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PCopyListWithRandPointer>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SCopyListWithRandPointer>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordBreakII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordBreakII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PLinkedListCycle>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SLinkedListCycle>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PLinkedListCycleII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SLinkedListCycleII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReorderList>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SReorderList>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreePreorderTraversal>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreePreorderTraversal>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBTreePostorderTraversal>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBTreePostorderTraversal>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PLRUCache>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SLRUCache>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PInsertionSortList>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SInsertionSortList>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PSortList>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SSortList>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PEvaluateReversePolishNotation>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SEvaluateReversePolishNotation>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMaxPointsLine>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMaxPointsLine>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReverseWords>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SReverseWords>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMaxProductSubarray>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMaxProductSubarray>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PFindMinInRotatedSortedArray>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SFindMinInRotatedSortedArray>();
  });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PFindMinInRotatedSortedArrayII>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SFindMinInRotatedSortedArrayII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMinStack>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMinStack>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PIntersectionOfTwoLL>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SIntersectionOfTwoLL>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PFindPeakElement>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SFindPeakElement>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMaxGap>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMaxGap>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PCmpVersionNum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SCmpVersionNum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PFractionToDecimal>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SFractionToDecimal>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PTwoSumIIInputArraySorted>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<STwoSumIIInputArraySorted>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PExcelSheetColTitle>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SExcelSheetColTitle>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMajorityElement>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMajorityElement>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PExcelSheetColNum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SExcelSheetColNum>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PFactorialTrailingZeroes>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SFactorialTrailingZeroes>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PBSTIterator>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SBSTIterator>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRepeatedDNASeq>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRepeatedDNASeq>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PBTRightSideView>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SBTRightSideView>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PKthLargestElement>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SKthLargestElement>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PUglyNumberII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SUglyNumberII>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PBestTimeToBuySellStockIV>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBestTimeToBuySellStockIV>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRotateArray>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRotateArray>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReverseBits>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SReverseBits>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PNumOfOneBits>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SNumOfOneBits>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PNumOfIslands>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SNumOfIslands>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PDungeonGame>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SDungeonGame>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PBitWiseANDOfNumRange>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SBitWiseANDOfNumRange>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PHappyNumber>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SHappyNumber>(); });

  handle->registerProblem([]() -> ArcProblem {
    return std::make_shared<PRemoveLinkedListElements>();
  });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SRemoveLinkedListElements>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PCountPrimes>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SCountPrimes>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PIsomorphicStrings>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SIsomorphicStrings>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PReverseLinkedList>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SReverseLinkedList>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PCourseSchedule>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SCourseSchedule>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PImplTriePrefixTree>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SImplTriePrefixTree>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PMinSizeSubarraySum>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SMinSizeSubarraySum>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PCourseScheduleII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SCourseScheduleII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordsDataStructure>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordsDataStructure>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PWordSearchII>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SWordSearchII>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PShortestPalindrome>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SShortestPalindrome>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PTheSkylineProblem>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<STheSkylineProblem>(); });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PImplStackUsingQueues>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SImplStackUsingQueues>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PContainsDuplicateIII>(); });
  handle->registerSolution([]() -> ArcSolution {
    return std::make_shared<SContainsDuplicateIII>();
  });

  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PRectangleArea>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SRectangleArea>(); });

  return 0;
}
