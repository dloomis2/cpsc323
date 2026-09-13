
// Lexeme Preprocessor

#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>
#include <vector>


int main(int argc, char* argv[])
{
  // Commandline argv[1] is the input file
  std::vector<std::string> cli{argv, argc + argv};
  if (cli.size() < 2) std::cerr << "[ERROR] Specify an Input File " << std::endl;

  std::string filename = cli.at(1);

  // Input stream and char counter for reading line by line
  std::ifstream fin(filename);
  char character;

  // Output stream for creating "output.txt"
  std::ofstream fout("output.txt");

  // Terminate program if no file is opened
  if(!fin.is_open()) std::cerr << "[WARNING] Could not Open File\n\n";

  // std::ws is for getting rid of whitespace
  while(fin.get(character) >> std::ws)
  {

    // Separate each statement on a new line (Semicolon is the delimiter)
    if (character  == ';')
    {
      fout << character << '\n';
      continue;
    }

    if (character == '/')
    {
      if (fin.peek() == '/')
      {
        // Ignore comments until end of line
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      // For skipping multi line comments
      if (fin.peek() == '*')
      {
        // Ignore until end of line
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      // For printing the division operator
      fout << character;
      continue;
    }

    // Print out normally
    else fout << character;
  }
  return 0;
}
