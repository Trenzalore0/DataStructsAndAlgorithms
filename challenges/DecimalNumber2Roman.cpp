#include <iostream>
#include <vector>

typedef std::vector<std::pair<int, std::pair<bool, std::string>>> numberRomanStruct;

void execute() {

  numberRomanStruct translation = {
    { 1000, { true, "M" } },{ 500, { false, "D" } },{ 100, { true, "C" } }, { 50, { false, "L" } }, { 10, { true, "X" } }, { 5, { false, "V" } }, { 1, { true, "I" } }
  };

  int numberChoossed = 0, savedNumber, index = 0;

  std::cout << "Enter with a number: " << std::endl;
  std::cin >> numberChoossed;
  std::cout.put('\n');

  savedNumber = numberChoossed;

  std::vector<int> numberDecomposite = std::vector<int>();

  int decomposite = 0;
  while (true) {

    auto algo = translation[index].second;

    if (!algo.first) {
      index++;
      continue;
    }

    int romanNumberInDecimal = translation[index].first;

    if (savedNumber == 0) {
      numberDecomposite.push_back(decomposite);
      break;
    }

    if (savedNumber < romanNumberInDecimal) {
      if (index + 1 != translation.size()) {
        if (decomposite != 0) {
          numberDecomposite.push_back(decomposite);
          decomposite = 0;
        }
        index++;
      }
      continue;
    }

    if (index + 1 != translation.size() && savedNumber - romanNumberInDecimal < 0) {
      index++;
      continue;
    }

    decomposite += romanNumberInDecimal;
    savedNumber -= romanNumberInDecimal;
  }
  index = 0;

  std::string output;
  for (int& num : numberDecomposite) {

    savedNumber = num;
    for (; savedNumber != 0;) {
      int sub = translation[index].first;
      std::string value = translation[index].second.second;

      for (int i = 1; i < 3; i++) {
        if (savedNumber + translation[index + i].first == sub && sub > savedNumber &&
          savedNumber != translation[index + i].first) {

          int sub2 = sub - translation[index + i].first;
          std::string value2 = translation[index + i].second.second;

          output.append(value2);
          output.append(value);
          savedNumber -= sub2;
          break;
        }
      }

      if (savedNumber < sub) {
        index++;
        continue;
      }
      savedNumber -= sub;
      output.append(translation[index].second.second);
    }
  }

  std::cout << "The number " << numberChoossed << " is " << output << " in roman number" << std::endl;
}
