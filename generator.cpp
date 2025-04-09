#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <array>

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

    char types[height][width];
    int extremes[height][width];

    //seed the random number generator with the current time for better pseudo-randomness
    srand(time(0));

    int counter = totalTiles - unallocated;

    //was going to make a separate function, but passing a 2D array into a function with variable characteristics is a no-go
    
    while(counter > 0) {
        int row;
        int col;
        
        while (true) {
            row = rand() % (height-1);
            col = rand() % (width-1);
            if (types[row][col] == NULL) break;
        }

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

        std::vector<char> shufftiles;
        //shuffle poptiles vector (into shufftiles vector) for pseudo-random occurrence of each tile instance
        // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
        // https://www.pcg-random.org/posts/bounded-rands.html
        // how random do i really need it?
        

        int extremeness = (rand() % 5) + 1;

        types[row][col] = shufftiles.at(counter-1);
        extremes[row][col] = extremeness;

        counter--;
    }

    // fill in "unallocated" tiles for the blank value
    for (int i = 0; i <= height; i++){
        for (int j = 0; j <= width; j++){
            if (types[height][width] == NULL) {
                types[height][width] = '0';
                extremes[height][width] = 0;
            }
        }
    }
    
    //create each string
    //prompt for save location
        //create file
    //add each string to the file
    //confirm file creation
        //return path to file

    return 0;
}