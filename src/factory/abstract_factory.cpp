#include <iostream>
#include <string>
#include <memory>
using namespace std;


//-------------------------------------------------------------
class Widget
{
public:
    virtual ~Widget() {}
    virtual void draw() = 0;
};


//-------------------------------------------------------------
class Button : public Widget
{
public:
    void draw() override {
        cout << "Button has been painted!\n";
    }
};


//-------------------------------------------------------------
class MaterialButton : public Widget
{
public:
    void draw() override {
        cout << "Material button has been painted!\n";
    }
};


//-------------------------------------------------------------
class Slider : public Widget
{
public:
    void draw() override {
        cout << "Slider has been painted!\n";
    }
};


//-------------------------------------------------------------
class MaterialSlider : public Widget
{
public:
    void draw() override {
        cout << "Material slider has been painted!\n";
    }
};


//-------------------------------------------------------------
class WidgetFactory
{
public:
    virtual ~WidgetFactory() {}
    virtual unique_ptr<Widget> getWidget(string_view widgetType) = 0;
};


//-------------------------------------------------------------
class NativeWidgetFactory : public WidgetFactory
{
public:
    virtual ~NativeWidgetFactory() {}

    unique_ptr<Widget> getWidget(string_view widgetType) override
    {
        if (widgetType == "button") {
            return make_unique<Button>();
        } else if (widgetType == "slider") {
            return make_unique<Slider>();
        } else {
            return nullptr;
        }
    }
};


//-------------------------------------------------------------
class MaterialWidgetFactory : public WidgetFactory
{
public:
    virtual ~MaterialWidgetFactory() {}

    unique_ptr<Widget> getWidget(string_view widgetType) override
    {
        if (widgetType == "button") {
            return make_unique<MaterialButton>();
        } else if (widgetType == "slider") {
            return make_unique<MaterialSlider>();
        } else {
            return nullptr;
        }
    }
};


//-------------------------------------------------------------
auto getWidgetFactory(bool materialDesign = false) -> unique_ptr<WidgetFactory>
{
    if (materialDesign) {
        return make_unique<MaterialWidgetFactory>();
    } else {
        return make_unique<NativeWidgetFactory>();
    }
}


//-------------------------------------------------------------
void drawWidgets(const unique_ptr<WidgetFactory>& factory)
{
    auto button = factory->getWidget("button");
    button->draw();

    auto slider = factory->getWidget("slider");
    slider->draw();
}



//-------------------------------------------------------------
int main()
{
    cout << "Drawing native widgets...\n";
    cout << "--------------------------------------\n";

    auto nativeFactory = getWidgetFactory();
    drawWidgets(nativeFactory);


    cout << "\nDrawing material design widgets...\n";
    cout << "--------------------------------------\n";

    auto materialFactory = getWidgetFactory(true);
    drawWidgets(materialFactory);

    return 0;
}
