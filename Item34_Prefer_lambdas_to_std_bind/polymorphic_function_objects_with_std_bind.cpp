class PolyWidget {
public:
    template<typename T>
    void operator()(const T& param);
}

PolyWidget pw;

auto boundPW = std::bind(pw, _1);


int main()
{

    boundPW(1930);         // pass int to
                           // PolyWidget::operator()

    boundPW(nullptr);      // pass nullptr to
                           // PolyWidget::operator()

    boundPW("Rosebud");    // pass string literal to
                           // PolyWidget::operator()
}
