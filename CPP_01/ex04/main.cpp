/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 06:14:18 by fvoicu            #+#    #+#             */
/*   Updated: 2024/05/10 02:41:58 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/**
* Replace all occurences of 'from' with 'to' in 'source'.
* @param source The string in which replacements will be made.
* @param from   The substring to be replaced.
* @param to     The substring to replace 'from' with.
*/
void replaceString(std::string& source, \
            const std::string& from, const std::string& to) {
  if (from.empty()) return;

  std::string result;  // Store the modified string
  std::size_t startPos = 0;  // Starting position for the search
  std::size_t findPos;

  while ((findPos = source.find(from, startPos)) \
          != std::string::npos) {
    result.append(source, startPos, findPos - startPos);
    result.append(to);
    startPos = findPos + from.length();
  }

  result.append(source, startPos, std::string::npos);
  source.swap(result);
}

/**
 * Process a file by repalcing occurences of 's1' with 's2'
 * in each line and writing the result to a new file.
 * @param filename The name of the file processed.
 * @param s1       The substr to be replaced.
 * @param s2       The substr to replace 's1' with.
 * @throws std::runtime_error if there are any errors
 *         in file operations.
*/
void processFile(const std::string& filename, \
          const std::string& s1, const std::string& s2) {
  // Open input file
  std::ifstream inFile(filename);
  if (!inFile) {
    throw std::runtime_error("Failed to open the file: " + filename);
  }

  // Create output file
  std::string newFilename = filename + ".replace";
  std::ofstream outFile(newFilename);
  if (!outFile) {
    throw std::runtime_error("Failed to create the file: " + newFilename);
  }

  // Process each line of input file
  std::string line;
  while (getline(inFile, line)) {
    replaceString(line, s1, s2);
    outFile << line << "\n";
  }
}

/**
 * Entry point of the program. Takes three command-line arguments:
 * 1. Filename: The name of the file to be processed.
 * 2. String to replace: The substring to be replaced in the file.
 * 3. New string: The substring to replace occurrences of the 'string to replace'.
 * 
 * @param ac The number of command-line arguments.
 * @param av An array of command-line argument strings.
 * @return 0 if the program executes successfully, 1 otherwise.
 */
int main(int ac, char** av) {
  if (ac != 4) {
    std::cerr << "Usage: " << av[0] << \
    " <filename> <string to replace> <new string>" \
    << std::endl;
    return 1;
  }

  // Extract command-line arguments
  std::string filename(av[1]);  // Filename to be processed
  std::string s1(av[2]);        // String to be replaced
  std::string s2(av[3]);        // String that will replace

  try {
    processFile(filename, s1, s2);
    std::cout << "File processing complete. Output file: " \
              << filename + ".replace" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
