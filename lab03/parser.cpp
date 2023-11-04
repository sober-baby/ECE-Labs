//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape **shapesArray = NULL;

// The number of shapes in the database, to be incremented
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes = 0;
// ECE244 Student: you may want to add the prototype of
// helper functions you write here

//keep on checking spaces until find a non-space character
void skipSpace(stringstream &lineStream){
    if(lineStream.eof()){
        return;
    }
    while (lineStream.peek() == ' '){
        lineStream.ignore();
    }
}

string keywords[] = {"maxShapes", "create", "move", "rotate", "draw", "delete", "all", "circle", "ellipse", "rectangle", "triangle"};

int main()
{
    bool error, iscircle;
    int maxShapesCount = 0;

    while (!cin.eof())
    {
        string command;
        string line;
        cout << "> "; // Prompt for input
        getline(cin, line);

        error = false;
        iscircle = false;
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream(line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        if (lineStream.eof()){
            cout << "Error: empty line" << endl;
            continue;
        }
        
        lineStream >> command;
        if (lineStream.fail() && !cin.eof()){
            cout << "Error: invalid command" << endl;
            continue;
        }
        
        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        if (command == "maxShapes")
        {
            skipSpace(lineStream);
            if (lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> max_shapes;
            skipSpace(lineStream);
            if (lineStream.fail()){
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(!lineStream.eof()){
                cout << "Error: too many arguments" << endl;
                continue;
            }else if (max_shapes < 1){
                cout << "Error: invalid value" << endl;
                continue;
            }else{
                if(maxShapesCount == 0){
                    shapesArray = new Shape *[max_shapes];
                    maxShapesCount = 1;
                }else{
                    for(int i = 0; i < shapeCount; i++){
                        delete shapesArray[i];
                    }
                    delete[] shapesArray;
                    shapesArray = new Shape *[max_shapes];
                }
                cout << "New database: max shapes is " << max_shapes << endl;
                continue;
            }
        }
        else if (command == "create")
        {
            string name, type;
            int x_location, y_location, x_size, y_size;
            // name
            skipSpace(lineStream);
            if (lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> name;
            skipSpace(lineStream); 
            if (lineStream.fail()){
                cout << "Error: invalid argument" << endl;
                continue; 
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            for(int i = 0; i < 11; i++){
                if (name == keywords[i]){
                    cout << "Error: invalid shape name" << endl;
                    error = true;
                    continue;
                    break;
                }
            }
            for (int i = 0; i < shapeCount; i++)
            {
                if (shapesArray[i]->getName() == name)
                {
                    cout << "Error: shape " << name << " exists" << endl;
                    error = true;
                    continue;
                    break;
                }
            }
            if (error)
            {
                continue;
            }

            // type
            lineStream >> type;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            for (int i = 0; i < NUM_TYPES; i++)
            {
                if (type == shapeTypesList[i])
                {
                    if(type == "circle"){
                        iscircle = true;
                    }
                    break;
                }
                else if (i == NUM_TYPES - 1)
                {
                    cout << "Error: invalid shape type" << endl;
                    error = true;
                }
            }
            if (error)
            {
                continue;
            }

            // xloc
            lineStream >> x_location;
            skipSpace(lineStream);
            if (lineStream.fail()){
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }else if (x_location < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }

            // yloc
            lineStream >> y_location;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }else if (y_location < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }
            

            // xsize
            lineStream >> x_size;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }else if (x_size < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }

            // ysize
            lineStream >> y_size;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(!lineStream.eof()){
                cout << "Error: too many arguments" << endl;
                continue;
            }
                else if (iscircle && y_size != x_size){
                cout << "Error: invalid value" << endl;
                continue;
            }else if (y_size < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }else if (shapeCount == max_shapes)
            {
                cout << "Error: shape array is full" << endl;
                continue;
            }else{
                shapesArray[shapeCount] = new Shape(name, type, x_location, x_size, y_location, y_size);
                shapeCount++;
                cout << "Created " << name << ": " << type << " " << x_location << " " << y_location << " " << x_size << " " << y_size << endl;
                continue;
            }
            }
        else if (command == "move")
        {

            string name;
            int x_location, y_location;
            

            // name
            skipSpace(lineStream);
            if (lineStream.eof())
            {
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> name;
            skipSpace(lineStream);
            if (shapeCount == 0){
                cout << "Error: shape " << name << " not found" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            int i = 0;
            while (i < shapeCount)
            {
                if (shapesArray[i]->getName() == name)
                {
                    break;
                }
                else if (i == shapeCount - 1)
                {
                    cout << "Error: shape " << name << " not found" << endl;
                    error = true;
                }
                i++;
            }
            if (error)
            {
                continue;
            }

            // xloc
            lineStream >> x_location;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }else if (x_location < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }
            

            // yloc
            lineStream >> y_location;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if (!lineStream.eof())
            {
                cout << "Error: too many arguments" << endl;
                continue;
            }
                
            else if (y_location < 0)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }else{
                shapesArray[i]->setXlocation(x_location);
                shapesArray[i]->setYlocation(y_location);
                cout << "Moved " << name << " to " << x_location << " " << y_location << endl;
                continue;
            }
        }
        else if (command == "rotate")
        {
            string name;
            int angle;
            int i = 0;
            // name
            skipSpace(lineStream);
            if (lineStream.eof())
            {
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> name;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }else if (shapeCount == 0)
            {
                cout << "Error: shape " << name << " not found" << endl;
                continue;
            }
            while (i < shapeCount)
            {
                if (shapesArray[i]->getName() == name)
                {
                    break;
                }
                else if (i == shapeCount - 1)
                {
                    cout << "Error: shape " << name << " not found" << endl;
                    error = true;
                }
                i++;
            }
            if (error){
                continue;
            }

            lineStream >> angle;
            skipSpace(lineStream);
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if (!lineStream.eof())
            {
                cout << "Error: too many arguments" << endl;
                continue;
            }else if (angle < 0 || angle > 360)
            {
                cout << "Error: invalid value" << endl;
                continue;
            }else{
                shapesArray[i]->setRotate(angle);
                cout << "Rotated " << name << " by " << angle << " degrees" << endl;
                continue;
            }
        }
        else if (command == "draw")
        {
            string unknown;
            int i = 0;
            // name
            skipSpace(lineStream);
            if (lineStream.eof()){
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> unknown;
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if(shapeCount == 0 && unknown != "all"){
                cout << "Error: shape " << unknown << " not found" << endl;
                continue;
            }else if(lineStream.peek() == ' '){
                cout << "Error: too many arguments" << endl;
                continue;
            }
            
            if (unknown == "all"){
                cout << "Drew all shapes" << endl;
                for (int j = 0; j < shapeCount; j++){
                    shapesArray[j]->draw();
                }
                continue;
            }else{
                while (i < shapeCount){
                    if (shapesArray[i]->getName() == unknown){
                        break;
                    }else if (i == shapeCount - 1)
                    {
                        cout << "Error: shape " << unknown << " not found" << endl;
                        error = true;
                    }
                    i++;
                }
                if (error)
                {
                    continue;
                }else{
                    cout << "Drew ";
                }
                shapesArray[i]->draw();
                continue;
            }
            // Once the command has been processed, prompt for the
            // next command
        }else if(command == "delete"){
            string unkown;
            int i = 0;
            if (lineStream.eof())
            {
                cout << "Error: too few arguments" << endl;
                continue;
            }
            lineStream >> unkown;
            if (lineStream.fail())
            {
                cout << "Error: invalid argument" << endl;
                continue;
            }else if (shapeCount == 0 && unkown != "all"){
                cout << "Error: shape " << unkown << " not found" << endl;
                continue;
            }else if(lineStream.peek() == ' '){
                cout << "Error: too many arguments" << endl;
                continue;
            }
            if (unkown == "all"){
                cout << "Deleted: all shapes " << endl;
                for (int j = 0; j < shapeCount; j++)
                {
                    delete shapesArray[j];
                }
            shapeCount = 0;
            continue;
            }else{
                while (i < shapeCount){
                    if (shapesArray[i]->getName() == unkown){
                        break;
                    }else if (i == shapeCount - 1)
                    {
                        cout << "Error: shape " << unkown << " not found" << endl;
                        error = true;
                    }
                    i++;
                }
                if (error)
                {
                    continue;
                }else{
                    cout << "Deleted shape " << unkown << endl;
                }
                delete shapesArray[i];
                for (int j = i; j < shapeCount - 1; j++)
                {
                    shapesArray[j] = shapesArray[j + 1];
                }
                shapeCount--;
                continue;
            }
        }else{
            if(!cin.eof()){
            cout << "Error: invalid command" << endl;
            }
            continue;
        }
    } // End input loop until EOF.
}

