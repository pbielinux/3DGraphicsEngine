#ifndef INC_3DGRAPHICS_INITIALIZER_H
# define INC_3DGRAPHICS_INITIALIZER_H

# include <memory>
# include <vector>
# include <iostream>

class Initializer {
public:
    Initializer();

    virtual void setup() = 0;
    virtual void teardown() = 0;

    void initialize();
    void shutdown();

    bool is_initialized() const;
    bool is_freed() const;

private:
    bool initialized;
    bool freed;
};

class Startup {
public:
    void add_initializer(std::shared_ptr<Initializer> initializer);

    void init();
    void shutdown();

private:
    std::vector<std::shared_ptr<Initializer>> initializers;
};

#endif //INC_3DGRAPHICS_INITIALIZER_H
