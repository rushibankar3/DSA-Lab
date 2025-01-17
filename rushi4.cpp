/* To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iterator>

class Set {
private:
    std::unordered_set<int> elements;

public:
    // Add a new element to the set
    void add(int element) {
        elements.insert(element);
    }

    // Remove an element from the set
    void remove(int element) {
        elements.erase(element);
    }

    // Check if the set contains the element
    bool contains(int element) const {
        return elements.find(element) != elements.end();
    }

    // Return the number of elements in the set
    size_t size() const {
        return elements.size();
    }

    // Return an iterator to loop over the set
    std::unordered_set<int>::iterator iterator() {
        return elements.begin();
    }

    // Return a new set that is the intersection of this set and another set
    Set intersection(const Set& other_set) const {
        Set result;
        for (const int& element : elements) {
            if (other_set.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Return a new set that is the union of this set and another set
    Set unionSet(const Set& other_set) const {
        Set result = *this; // Start with the current set
        for (const int& element : other_set.elements) {
            result.add(element);
        }
        return result;
    }

    // Return a new set that is the difference of this set and another set
    Set difference(const Set& other_set) const {
        Set result;
        for (const int& element : elements) {
            if (!other_set.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Check if this set is a subset of another set
    bool subset(const Set& other_set) const {
        for (const int& element : elements) {
            if (!other_set.contains(element)) {
                return false;
            }
        }
        return true;
    }

    // Print the elements of the set
    void print() const {
        std::cout << "{ ";
        for (const int& element : elements) {
            std::cout << element << " ";
        }
        std::cout << "}" << std::endl;
    }
};

// Example usage
int main() {
    Set set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);

    std::cout << "Set 1 contains 2: " << set1.contains(2) << std::endl;  // True
    std::cout << "Set 1 size: " << set1.size() << std::endl;              // 3

    Set intersection_set = set1.intersection(set2);
    std::cout << "Intersection of Set 1 and Set 2: ";
    intersection_set.print();  // { 2 3 }

    Set union_set = set1.unionSet(set2);
    std::cout << "Union of Set 1 and Set 2: ";
    union_set.print();  // { 1 2 3 4 }

    Set difference_set = set1.difference(set2);
    std::cout << "Difference of Set 1 and Set 2: ";
    difference_set.print();  // { 1 }

    std::cout << "Set 1 is a subset of Set 2: " << set1.subset(set2) << std::endl;  // False

    return 0;
}



