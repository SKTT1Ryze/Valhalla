#include "registration.h"

#include "../leetcode-cc/BinaryTreeInorderTraversal.hpp"
#include "../leetcode-cc/DecodeWays.hpp"
#include "../leetcode-cc/DivideTwoIntegers.hpp"
#include "../leetcode-cc/FourSum.hpp"
#include "../leetcode-cc/GenerateParentheses.hpp"
#include "../leetcode-cc/GrayCode.hpp"
#include "../leetcode-cc/IntegerToRoman.hpp"
#include "../leetcode-cc/LargestRectangleInHistogram.hpp"
#include "../leetcode-cc/LetterCombsOfAPhoneNum.hpp"
#include "../leetcode-cc/LongestCommonPrefix.hpp"
#include "../leetcode-cc/MaximalRectangle.hpp"
#include "../leetcode-cc/MergeKSortedLists.hpp"
#include "../leetcode-cc/MergeSortedArray.hpp"
#include "../leetcode-cc/MergeTwoSortedLists.hpp"
#include "../leetcode-cc/NextPermutation.hpp"
#include "../leetcode-cc/PartitionList.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedList.hpp"
#include "../leetcode-cc/RemoveDuplicatesFromSortedListII.hpp"
#include "../leetcode-cc/RemoveElement.hpp"
#include "../leetcode-cc/RemoveNthNode.hpp"
#include "../leetcode-cc/RestoreIpAddresses.hpp"
#include "../leetcode-cc/ReverseLinkedListII.hpp"
#include "../leetcode-cc/ReverseNodesinKGroup.hpp"
#include "../leetcode-cc/RomanToInteger.hpp"
#include "../leetcode-cc/ScrambleString.hpp"
#include "../leetcode-cc/SearchInRotaedSortedArray.hpp"
#include "../leetcode-cc/SubsetsII.hpp"
#include "../leetcode-cc/ThreeSum.hpp"
#include "../leetcode-cc/ThreeSumClosest.hpp"
#include "../leetcode-cc/UniqueBinarySearchTrees.hpp"
#include "../leetcode-cc/ValidParentheses.hpp"

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

  return 0;
}
