#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <filesystem>

#include "prettyheader.h"

int main() {
    std::cout << head << std::endl;

    std::cout << "The following generates a .txt file to be used on the Map Drawer site." << std::endl << std::endl;

    std::cout << "A series of prompts will ask for whole number values (>=0) corresponding to various elements of the map." << std::endl << std::endl;

    std::cout << "There is no backing up a step. The format of the prompts will be provided prior to the prompts ocurring in sequence for user input." << std::endl;
    std::cout << "You are encouraged to jot notes for speedier entry." << std::endl << std::endl;

    std::cout << "You will be asked, in order:" << std::endl;
    std::cout << "- The number of tiles in HEIGHT of your map" << std::endl;
    std::cout << "- The number of tiles in WIDTH of your map" << std::endl << std::endl;

    std::cout << "At this stage you will be informed how many tiles you have for placing features. (HEIGHT x WIDTH)" << std::endl << std::endl;

    std::cout << "You will then be asked, in order:" << std::endl;
    std::cout << "- The number of SETTLEMENT tiles you would like on your map (n <= HEIGHT x WIDTH)" << std::endl;
    std::cout << "- The number of VALLEY tiles you would like on your map (n <= (HEIGHT x WIDTH) - number of allocated tiles)" << std::endl;
    std::cout << "- The number of FOREST tiles you would like on your map (n <= (HEIGHT x WIDTH) - number of allocated tiles)" << std::endl;
    std::cout << "- The number of MOUNTAIN tiles you would like on your map (n <= (HEIGHT x WIDTH) - number of allocated tiles)" << std::endl;
    std::cout << "- The number of RIVER tiles you would like on your map (n <= (HEIGHT x WIDTH) - number of allocated tiles)" << std::endl << std::endl;

    std::cout << "At each stage, you will be told how many times you have allocated, what type of tiles they are, and how many unallocated tiles you have remaining." << std::endl;
    std::cout << "Unallocated tiles will be marked as blank. You are encouraged to leave some blank tiles." << std::endl << std::endl;

    std::cout << "You will now be prompted for input." << std::endl << std::endl;

    int height = 0;
    int width = 0;
    int settlements = 0;
    int valleys = 0;
    int forests = 0;
    int mountains = 0;
    int rivers = 0;

    std::cout << "How many tiles in HEIGHT do you want for your map? ";
    std::cin >> height;
    while(std::cin.fail() || height < 0){
        std::cout << "ERROR. Please enter a whole number >= 0." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many tiles in HEIGHT do you want for your map? ";
        std::cin >> height;
    }
    std::cout << "How many tiles in WIDTH do you want for your map? ";
    std::cin >> width;
    while(std::cin.fail() || height < 0){
        std::cout << "ERROR. Please enter a whole number >= 0." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many tiles in WIDTH do you want for your map? ";
        std::cin >> width;
    }

    int totalTiles = height * width;
    int unallocated = totalTiles;
    std::cout << std::endl;
    std::cout << "You have " <<  totalTiles << " total tiles available for allocation." << std::endl << std::endl;

    std::cout << "How many SETTLEMENT tiles would you like on your map? ";
    std::cin >> settlements;
    while(std::cin.fail() || settlements < 0 || settlements > unallocated){
        std::cout << "ERROR. Please enter a whole number between 0 and " << totalTiles << "." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many SETTLEMENT tiles would you like on your map? ";
        std::cin >> settlements;
    }
    unallocated -= settlements;

    std::cout << std::endl;
    std::cout << "You have " << unallocated << " remaining unallocated tiles." << std::endl;
    std::cout << "How many VALLEY tiles would you like on your map? ";
    std::cin >> valleys;
    while (std::cin.fail() || valleys < 0 || valleys > unallocated) {
        std::cout << "ERROR. Please enter a whole number between 0 and " << totalTiles << "." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many VALLEY tiles would you like on your map? ";
        std::cin >> valleys;
    }
    unallocated -= valleys;

    std::cout << std::endl;
    std::cout << "You have " << unallocated << " remaining unallocated tiles." << std::endl;
    std::cout << "How many FOREST tiles would you like on your map? ";
    std::cin >> forests;
    while (std::cin.fail() || forests < 0 || forests > unallocated) {
        std::cout << "ERROR. Please enter a whole number between 0 and " << totalTiles << "." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many FOREST tiles would you like on your map? ";
        std::cin >> forests;
    }
    unallocated -= forests;

    std::cout << std::endl;
    std::cout << "You have " << unallocated << " remaining unallocated tiles." << std::endl;
    std::cout << "How many MOUNTAIN tiles would you like on your map? ";
    std::cin >> mountains;
    while (std::cin.fail() || mountains < 0 || mountains > unallocated) {
        std::cout << "ERROR. Please enter a whole number between 0 and " << totalTiles << "." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many MOUNTAIN tiles would you like on your map? ";
        std::cin >> mountains;
    }
    unallocated -= mountains;

    std::cout << std::endl;
    std::cout << "You have " << unallocated << " remaining unallocated tiles." << std::endl;
    std::cout << "How many RIVER tiles would you like on your map? ";
    std::cin >> rivers;
    while (std::cin.fail() || rivers < 0 || rivers > unallocated) {
        std::cout << "ERROR. Please enter a whole number between 0 and " << totalTiles << "." << std:: endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "How many RIVER tiles would you like on your map? ";
        std::cin >> rivers;
    }
    unallocated -= rivers;
    
    std::cout << std::endl << std::endl;
    std::cout << "Your map will have: " 
        << settlements << " settlements, "
        << valleys << " valleys, "
        << forests << " forests, "
        << mountains << " mountains, and "
        << rivers << " rivers." << std::endl;
    std::cout << "The remaining " << unallocated << " tiles will be left blank." << std::endl;

    std::vector<std::vector<char>> types(height, std::vector<char>(width,'P'));
    std::vector<std::vector<int>> extremes(height, std::vector<int>(width, 0));

    //seed the random number generator with the current time for better pseudo-randomness
    std::mt19937 gen(time(0));

    std::vector<char> poptiles;
    for (int i = 0; i < settlements; i++){
        poptiles.push_back('S');
    }
    for (int i = 0; i < forests; i++){
        poptiles.push_back('F');
    }
    for (int i = 0; i < valleys; i++){
        poptiles.push_back('V');
    }
    for (int i = 0; i < rivers; i++){
        poptiles.push_back('R');
    }
    for (int i = 0; i < mountains; i++){
        poptiles.push_back('M');
    }

    //shuffle poptiles vector for pseudo-random occurrence of each tile instance
    // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
    // https://www.pcg-random.org/posts/bounded-rands.html
    std::shuffle(poptiles.begin(), poptiles.end(), gen);

    int counter = totalTiles - unallocated;

    std::uniform_int_distribution<> rowDist(0,height-1);
    std::uniform_int_distribution<> colDist(0,width-1);
    std::uniform_int_distribution<> extrDist(1,5);

    //was going to make a separate function, but passing a 2D array into a function with variable characteristics is a no-go
    // std::cerr << "entering loop" << std::endl;
    while(counter > 0) {
        int row;
        int col;
        
        while (true) {
            row = rowDist(gen);
            col = colDist(gen);
            if (types[row][col] == 'P') break;
        }
        // std::cerr << "tile selected" << std::endl;

        int extremeness = extrDist(gen);

        types[row][col] = poptiles.at(counter-1);
        extremes[row][col] = extremeness;

        counter--;
    }
    // std::cerr << "exited tile select loop" << std::endl;
    // fill in "unallocated" tiles for the blank value
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (types[i][j] == 'P') {
                types[i][j] = '0';
            }
        }
    }

    std::string filename = "";
    //prompt for save location
    std::cout << "Name your file: ";
    std::cin >> filename;
    if(filename.find(".txt")==std::string::npos) filename += ".txt";
    std::ofstream fstm(filename);

    //create file or catch error / confirm file creation
    while(!fstm.is_open()){
        std::cout << "Error creating file of name " << filename << " ; Please re-enter file name." << std::endl;
        std::cout << "File name: ";
        std::cin >> filename;
        if(!filename.find(".txt")) filename = filename + ".txt";
        std::ofstream fstm(filename);
    }
    
    // std::cerr << "entering printing" << std::endl;
    //create each string & add to file
    fstm << width << " " << height << std::endl;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if(j==width-1){
                fstm << "(" << types[i][j] << "," << extremes[i][j] << ")";
            }
            else fstm << "(" << types[i][j] << "," << extremes[i][j] << ") ";
        }
        fstm << std::endl;
    }

    //return path to file
    namespace fs = std::filesystem;
    std::cout << "Your file has been created at the following path: " << fs::current_path().string() << "/" << filename << std::endl;

    return 0;
}