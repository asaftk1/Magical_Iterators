#include <iostream>
#include <vector>
#include <iterator>

namespace ariel
{
    // class MagicalContainer

    class MagicalContainer
    {
    private:
        std::vector<int> container; // Dynamic array to store the container

    public:
        int size() const { return container.size(); }
        void addElement(int element) { container.push_back(element); }
        void removeElement(int element) { /* Implement your logic here */ }
        int getElement(std::size_t index) const { return container.at(index); }

        // AscendingIterator
        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;

        public:
            AscendingIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0) {}

            ~AscendingIterator() {}

            AscendingIterator &operator=(const AscendingIterator &other) { return *this; }
            bool operator==(const AscendingIterator &other) const { return currentIndex == other.currentIndex; }
            bool operator!=(const AscendingIterator &other) const { return currentIndex != other.currentIndex; }
            bool operator>(const AscendingIterator &other) const { return currentIndex > other.currentIndex; }
            bool operator<(const AscendingIterator &other) const { return currentIndex < other.currentIndex; }
            const int &operator*() const {return container.container[currentIndex];  }
            AscendingIterator &operator++() { ++currentIndex; return *this; }
            AscendingIterator begin() const { return *this; }
            AscendingIterator end() const { AscendingIterator iter(*this); iter.currentIndex = container.container.size(); return iter; }
        };

        // SideCrossIterator
        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;
            bool forward;

        public:
            SideCrossIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0), forward(true) {}

            ~SideCrossIterator() {}

            SideCrossIterator &operator=(const SideCrossIterator &other) { return *this; }
            bool operator==(const SideCrossIterator &other) const { return currentIndex == other.currentIndex; }
            bool operator!=(const SideCrossIterator &other) const { return currentIndex != other.currentIndex; }
            bool operator>(const SideCrossIterator &other) const { return currentIndex > other.currentIndex; }
            bool operator<(const SideCrossIterator &other) const { return currentIndex < other.currentIndex; }
            int operator*() const { return container.container[currentIndex];  }
            SideCrossIterator &operator++() { ++currentIndex; return *this; }
            SideCrossIterator begin() const { return *this; }
            SideCrossIterator end() const { SideCrossIterator iter(*this); iter.currentIndex = container.container.size(); return iter; }
        };

        // PrimeIterator
        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;
            bool IsPrimeFlag = false;

        public:
            PrimeIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0) {}

            ~PrimeIterator() {}

            PrimeIterator &operator=(const PrimeIterator &other) { return *this; }
            bool operator==(const PrimeIterator &other) const { return currentIndex == other.currentIndex; }
            bool operator!=(const PrimeIterator &other) const { return currentIndex != other.currentIndex; }
            bool operator>(const PrimeIterator &other) const { return currentIndex > other.currentIndex; }
            bool operator<(const PrimeIterator &other) const { return currentIndex < other.currentIndex; }
            int operator*() const { return container.container[currentIndex]; }
            PrimeIterator &operator++() { ++currentIndex; return *this; }
            PrimeIterator begin() const { return *this; }
            PrimeIterator end() const { PrimeIterator iter(*this); iter.currentIndex = container.container.size(); return iter; }
            bool isPrime(int num) const { /* Implement your logic here */ return true; }
        };
    };
}
