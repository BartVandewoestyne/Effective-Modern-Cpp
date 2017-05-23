/*
 * Key ideas:
 *
 *   1) For std::unique_ptr, the type of the deleter is part of the type of the
 *      smart pointer.  For std::shared_ptr, it's not.
 *
 *   2) The std::shared_ptr design is more flexible.
 *
 *   3) Constructing more than one std::shared_ptr from a single
 *      raw pointer results in undefined behavior.
 */

#include <iostream>
#include <memory>
#include <vector>

class Widget {
public:
    Widget() { std::cout << "Widget(" << this << ")" << std::endl; }
    ~Widget() { std::cout << "~Widget(" << this << ")" << std::endl; }
};

void makeLogentry(Widget *pw) { std::cout << "Log entry for " << pw << "." << std::endl; }

auto loggingDel = [](Widget *pw)        // custom deleter
                  {                     // (as in Item 19)
                    makeLogentry(pw);
                    delete pw;
                  };


int main()
{

    /* For std::unique_ptr, the type of the deleter is part of the type of the
     * smart pointer.  For std::shared_ptr, it's not.
     */

    std::cout << "Part 1: deleter type being part or not" << std::endl;
    
    std::unique_ptr<                       // deleter type is
      Widget, decltype(loggingDel)         // part of ptr type
      > upw(new Widget, loggingDel);
    
    std::shared_ptr<Widget>                // deleter type is not
      spw(new Widget, loggingDel);         // part of ptr type
    
    
    /* The std::shared_ptr design is more flexible: the type of the custom deleter
     * is not part of the shared_ptr type, so the following things are for example
     * possible:
     * 
     *   -> can be placed in containers of objects of the shared_ptr type
     *   -> they can be assigned to one another
     *   -> they can be passed to a function taking a parameter of
     *      type std::shared_ptr<Widget>.
     *   -> ...
     * 
     * None of these things can be done with std::unique_ptrs that differ in the
     * types of their custom deleters, because the type of the custom deleter would
     * affect the type of the std::unique_ptr.
     */
     
    std::cout << "Part 2: std::shared_ptr design being more flexible" << std::endl;

    auto customDeleter1 = [](Widget *pw) { makeLogentry(pw); delete pw; };  // custom deleters,
    auto customDeleter2 = [](Widget *pw) { makeLogentry(pw); delete pw; };  // each with a
                                                                            // different type
    
    std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
    std::shared_ptr<Widget> pw2(new Widget, customDeleter2);
    
    std::vector<std::shared_ptr<Widget>> vpw { pw1, pw2 };


   /*
    * BAD BAD BAD: constructing more than one std::shared_ptr from a single
    * raw pointer results in undefined behavior.
    */

    std::cout << "Part 3: std::shared_ptr construction error" << std::endl;
   
    //auto pw = new Widget;
    // 
    //std::shared_ptr<Widget> spw1(pw, loggingDel);  // create control
    //                                               // block for *pw
    //
    //std::shared_ptr<Widget> spw2(pw, loggingDel);  // create 2nd
    //                                               // control block
    //                                               // for *pw!
    
    std::shared_ptr<Widget> spw1(new Widget,       // direct use of new
                                 loggingDel);
    
    std::shared_ptr<Widget> spw2(spw1);            // spw2 uses same
                                                   // control block as spw1

    std::cout << "Part 4: right before end of main" << std::endl;
}                                                 
