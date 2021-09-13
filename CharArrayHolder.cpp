#include "main.hpp"

CharArrayHolder::CharArrayHolder(const char* arr) {
    std::memset(this->innerArray, '\0', sizeof(this->innerArray));
    std::memcpy(this->innerArray, arr, sizeof(this->innerArray));
}

void CharArrayHolder::serialize(std::ostream& os) {
    os << CHR_MARK;
    os.write(innerArray, sizeof innerArray);
    os << STOP;
    write_children(os);
}

BaseHolder* CharArrayHolder::deserialize(std::istream& is) {
    char buf[10] = {0};
    is.read(buf, 10);
    is.read(nullptr, 1);
    BaseHolder* ret = new CharArrayHolder(buf);
    return ret;
}


void CharArrayHolder::describe() const {
    std::cout << "Element is a CharArrayHolder with value: |" << this->innerArray << "|. It has " << this->children.size() << " children." << std::endl;
    if (this->children.size() > 0) {
        for(auto const& x: this->children) {
            x->describe();
    }
}