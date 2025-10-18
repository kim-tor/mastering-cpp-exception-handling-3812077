#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientDiskSpaceException : public std::runtime_error
{
  public:
  InsufficientDiskSpaceException(const std::string& msg) : std::runtime_error(msg){}
};

void checkDiskSpace(unsigned long availableSpaceMB)
{
  const unsigned long requiredSpaceMB = 100; 

  if(availableSpaceMB < requiredSpaceMB)
  {
    throw InsufficientDiskSpaceException("Insufficient Disk Space");
  }
}

int main()
{
  unsigned long spaceToTest[] = {120, 100, 80};

  for (unsigned long space : spaceToTest)
  {
    try
    {
      checkDiskSpace(space);
      std::cout << "Sufficient disk space: " << space << std::endl;
    }
    catch(const InsufficientDiskSpaceException& e)
    {
      std::cerr << "Error: " << e.what() << " Available space: " << space << "MB" << std::endl;
    }
    
  }
}