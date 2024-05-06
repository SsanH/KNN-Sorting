#include "DataManager.h"

using namespace std;

/**
 * gets a string and a delimiter and returns a vector of strings
 * @param string str
 * @param string delimiter
 * @return vector<string> vec
 */
vector<string> DataManager::parseString(string str, const string& delimiter) {

    int delSize = delimiter.size();
    int start, end = -1 * delSize;
    vector<string> vec;

    do {
        start = end + delSize;
        end = str.find(delimiter, start);

        string word = str.substr(start, end - start);
        if (word != "\0") {
            vec.push_back(word);
        }
    } while (end != -1);

    if (vec.size() > 0) {
        string s = vec[vec.size() - 1];
        if (s[s.size() - 1] == '\r') {
            vec[vec.size() - 1] = s.substr(0, s.size()-1);
        }
    }
    return vec;
}

/**
 * gets a string and checks if it is a valid number. returns bool
 * @param string s
 * @return bool
 */
bool DataManager::isNum(string s) {
    bool isDecimal = false;
    bool isScientificNotation = false;
    int size = s.size();

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            if (!(s[i] == '-' || isdigit(s[i]))) {
                if (s[i] == '.') {
                    isDecimal = true;
                    continue;
                }
                return false;
            }
        } else {
            if (!isdigit(s[i])) {
                if ((s[i] == 'E' || s[i] == 'e') && !isScientificNotation) {
                    isScientificNotation = true;
                    if (i == size - 1) {
                        continue;
                    }
                    if (s[i+1] == '+' || s[i+1] == '-') {
                        i++;
                        continue;
                    }
                    continue;
                }
                if (s[i] == '.' && !isDecimal) {
                    isDecimal = true;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * gets an output file stream and a vector<string> and writes the vector<string> as a row in csv format.
 * @param outFile
 * @param output
 */
void DataManager::writeLineCSV(ofstream& outFile, vector<string> output) {
    string lastStr = output.back();
    output.pop_back();
    for (string s : output) {
        outFile << s << ",";
    }
    outFile << lastStr << endl;
}

void DataManager::writeLine(ofstream &outFile, string output) {
    outFile << output << endl;
}

/**
 * gets an string input and a delimiter and returns a single DataPoint
 * @param input
 * @param delimiter
 * @return DataPoint
 */
DataPoint DataManager::getDataPoint(string input, const string& delimiter) {

    if (input.size() == 0) {
        cout << "no data provided" << endl;
        exit(0);
    }

    vector<double> properties;
    string tag = "";

    vector<string> parsedInput = parseString(input, delimiter);

    int size = parsedInput.size();

    for (int i = 0; i < size; i++) {

        if (isNum(parsedInput[i])) {
            try {
                properties.push_back(stod(parsedInput[i]));
            } catch (exception e) {
                cout << "invalid input" << endl;
                exit(0);
            }
        } else {
            if (i == size -1) {
                tag = parsedInput[i];
            } else {
                cout << "invalid input" << endl;
                exit(0);
            }
        }
    }
    if (tag.compare(input) == 0) {
        cout << "bad delimiter or no vector provided" << endl;
        exit(0);
    }
    return DataPoint(properties, tag);
}

/**
 * gets an input stream and a delimiter and returns a vector of DataPoints.
 * @param inStream
 * @param delimiter
 * @return vector<DataPoint> vec
 */
vector<DataPoint> DataManager::getDataPoints(std::istream &inStream, const string &delimiter) {
    vector<DataPoint> vec;
    while (!inStream.eof()) {

        string input;
        getline(inStream, input);

        if (input.size() > 0) {
            vec.push_back(getDataPoint(input, delimiter));
        } else {
            break;
        }
    }
    return vec;
}

/**
 * gets an input stream and a delimiter. returns a vector of type double containing the parsed input.
 * @param istream inStream
 * @param string delimiter
 * @return vector<double> vec
 */
vector<double> DataManager::getVector(std::istream &inStream, const std::string &delimiter) {
    string input;
    getline(inStream, input);
    DataPoint d = getDataPoint(input, delimiter);
    if (d.getTag().empty()) {
        return d.getProperties();
    } else {
     cout << "incorrect input" << endl;
        exit(0);
    }
}

/**
 * gets a string of data and processes it into the components needed for a request. returns a RequestData object
 * initialized with the data.
 * @param data
 * @return RequestDetail
 */
RequestDetails DataManager::getRequest(string data) {
    vector<double> vec;
    string dist = "";
    int k = -1;

    vector<string> parsedData = parseString(data, " ");

    for (string s : parsedData) {
        if (isNum(s)) {
        try {
                vec.push_back(stod(s));
            } catch (exception e) {
                return RequestDetails(vec, dist, k);
            }
            
        } else {
            dist = s;
            break;
        }
    }

    if (isNum(parsedData.back())) {
        k = stod(parsedData.back());
    }

    return RequestDetails(vec, dist, k);
}


