#include <string>

class Caeser {
  public:
    std::string cypher(std::string text, int shift_value);
    std::string decypher(std::string text, int shift_value);
    std::string crack(std::string text);
    Caeser(void);

  private:
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string upper(std::string text);
};
