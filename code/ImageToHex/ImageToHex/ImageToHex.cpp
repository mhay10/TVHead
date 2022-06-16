#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace cv;

template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& sep);
std::string toHex(std::string binary);

int main(int argc, char** argv) {
	if (argc != 2) {
		std::string progName = argv[0];
		std::cout << "Usage: " << progName.substr(progName.find_last_of("\\/") + 1) << " <img path>\n";
		return -1;
	}

	std::string path = argv[1];
	Mat img = imread(path, 0);
	const int width = img.rows, height = img.cols;

	std::vector<std::vector<int>> pixels(width, std::vector<int>(height));
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			pixels[i][j] = img.at<uchar>(i, j) < 255 ? 0 : 1;
		}
	}

	const int chop = 8;
	std::map<std::string, std::vector<std::string>> tiles;
	for (int i = 0; i < width; i += chop) {
		for (int j = 0; j < height; j += chop) {
			std::vector<std::string> tile;
			for (int k = 0; k < chop; k++) {
				std::string row;
				for (int l = 0; l < chop; l++) {
					row += std::to_string(pixels[i + k][j + l]);
				}
				tile.push_back(row);
			}
			
			std::stringstream ss;
			ss << "From (" << i << ", " << j << ") to (" << i + chop << ", " << j + chop << "): ";
			tiles[ss.str()] = tile;
		}
	}

	std::vector<std::string> allVals;
	for (auto tile : tiles) {
		std::cout << tile.first;
		std::vector<std::string> vals;
		for (std::string row : tile.second) {
			std::string val = toHex(row);
			vals.push_back(val);
			allVals.push_back(val);
		}

		std::cout << join(vals.begin(), vals.end(), ", ") << "\n";
	}

	std::cout << "\nRaw Hex Data: " << join(allVals.begin(), allVals.end(), ", ") << "\n";
}

static std::map<std::string, char> binToHex = {
	{"0000", '0'},
	{"0001", '1'},
	{"0010", '2'},
	{"0011", '3'},
	{"0100", '4'},
	{"0101", '5'},
	{"0110", '6'},
	{"0111", '7'},
	{"1000", '8'},
	{"1001", '9'},
	{"1010", 'a'},
	{"1011", 'b'},
	{"1100", 'c'},
	{"1101", 'd'},
	{"1110", 'e'},
	{"1111", 'f'},
};

std::string toHex(std::string binary) {
	std::string hex = "0x";
	for (int i = 0; i <= 8; i += 4) {
		hex += binToHex[binary.substr(i, 4)];
	}
	return hex;
}

template <typename Iter>
std::string join(Iter begin, Iter end, std::string const& sep) {
	std::ostringstream result;
	if (begin != end)
		result << *begin++;
	while (begin != end)
		result << sep << *begin++;

	return result.str();
}