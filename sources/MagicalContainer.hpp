#include <iostream>
#include <vector>
#include <iterator>

namespace ariel
{
    // class MagicalContainer;  // Forward declaration

    class MagicalContainer
    {
    private:
        std::vector<int> elements; // Dynamic array to store the elements

    public:
        int size()
        {
            return elements.size();
        }

        void addElement(int element)
        {
            elements.push_back(element);
        }

        void removeElement(int element)
        {
            for (auto it = elements.begin(); it != elements.end(); ++it)
            {
                if (*it == element)
                {
                    elements.erase(it);
                    break;
                }
            }
        }

        int getSize() const
        {
            return elements.size();
        }

        class AscendingIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;

        public:
            AscendingIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0) {}
            AscendingIterator begin()
            {
                return *this;
            }
            AscendingIterator end()
            {
                AscendingIterator iter = *this;
                iter.currentIndex = static_cast<typename std::vector<int>::size_type>(container.getSize());
                return iter;
            }

            bool hasNext() const
            {
                return currentIndex < container.elements.size();
            }

            int next()
            {
                int element = container.elements[currentIndex];
                currentIndex++;
                return element;
            }

            // Implement the dereference operator *
            int operator*() const
            {
                return container.elements[currentIndex];
            }

            // Implement the pre-increment operator ++
            AscendingIterator &operator++()
            {
                currentIndex++;
                return *this;
            }

            // Implement the inequality operator !=
            bool operator!=(const AscendingIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }
        };

        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;
            bool forward;

        public:
            SideCrossIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0), forward(true) {}

            SideCrossIterator begin()
            {
                return *this;
            }
            SideCrossIterator end()
            {
                SideCrossIterator iter = *this;
                iter.currentIndex = static_cast<typename std::vector<int>::size_type>(container.getSize());
                return iter;
            }

            bool hasNext() const
            {
                return currentIndex < container.elements.size();
            }

            int next()
            {
                int element = container.elements[currentIndex];
                if (forward)
                {
                    currentIndex++;
                    forward = false;
                }
                else
                {
                    currentIndex--;
                    forward = true;
                }
                return element;
            }

            // Implement the dereference operator *
            int operator*() const
            {
                return container.elements[currentIndex];
            }

            // Implement the pre-increment operator ++
            SideCrossIterator &operator++()
            {
                currentIndex++;
                return *this;
            }

            // Implement the inequality operator !=
            bool operator!=(const SideCrossIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            typename std::vector<int>::size_type currentIndex;

            bool isPrime(int num) const
            {
                if (num <= 1)
                {
                    return false;
                }
                for (int i = 2; i * i <= num; i++)
                {
                    if (num % i == 0)
                    {
                        return false;
                    }
                }
                return true;
            }

        public:
            PrimeIterator(const MagicalContainer &cont)
                : container(cont), currentIndex(0) {}

            PrimeIterator begin()
            {
                return *this;
            }
            PrimeIterator end()
            {
                PrimeIterator iter = *this;
                iter.currentIndex = static_cast<typename std::vector<int>::size_type>(container.getSize());
                return iter;
            }

            bool hasNext()
            {
                while (currentIndex < container.elements.size())
                {
                    if (isPrime(container.elements[currentIndex]))
                    {
                        return true;
                    }
                    currentIndex++;
                }
                return false;
            }

            int next()
            {
                int element = container.elements[currentIndex];
                currentIndex++;
                return element;
            }

            // Implement the dereference operator *
            int operator*() const
            {
                return container.elements[currentIndex];
            }

            // Implement the pre-increment operator ++
            PrimeIterator &operator++()
            {
                currentIndex++;
                return *this;
            }

            // Implement the inequality operator !=
            bool operator!=(const PrimeIterator &other) const
            {
                return currentIndex != other.currentIndex;
            }
        };
    };

}