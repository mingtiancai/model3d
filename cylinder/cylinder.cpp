#include "cylinder.h"

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCylinderSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

#include <array>

#include <QApplication>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>

#if VTK_VERSION_NUMBER >= 89000000000ULL
#define VTK890 1
#endif

#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>

Cylinder::Cylinder()
{
}

void Cylinder::show(int argc, char **argv)
{
    QEventLoop loop;

    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

    QVTKOpenGLNativeWidget widget;

    vtkNew<vtkNamedColors> colors;

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
#if VTK890
    widget.setRenderWindow(renderWindow);
#else
    widget.SetRenderWindow(renderWindow);
#endif

    widget.resize(600, 600);

    // Set the background color.
    std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
    colors->SetColor("BkgColor", bkg.data());

    // This creates a polygonal cylinder model with eight circumferential facets
    // (i.e, in practice an octagonal prism).
    vtkNew<vtkCylinderSource> cylinder;
    cylinder->SetResolution(8);

    // The mapper is responsible for pushing the geometry into the graphics
    // library. It may also do color mapping, if scalars or other attributes are
    // defined.
    vtkNew<vtkPolyDataMapper> cylinderMapper;
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    // The actor is a grouping mechanism: besides the geometry (mapper), it
    // also has a property, transformation matrix, and/or texture map.
    // Here we set its color and rotate it around the X and Y axes.
    vtkNew<vtkActor> cylinderActor;
    cylinderActor->SetMapper(cylinderMapper);
    cylinderActor->GetProperty()->SetColor(
        colors->GetColor4d("Tomato").GetData());
    cylinderActor->RotateX(30.0);
    cylinderActor->RotateY(-45.0);

    // The renderer generates the image
    // which is then displayed on the render window.
    // It can be thought of as a scene to which the actor is added
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(cylinderActor);
    renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
    // Zoom in a little by accessing the camera and invoking its "Zoom" method.
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(1.5);

#if VTK890
    widget.renderWindow()->AddRenderer(renderer);
    widget.renderWindow()->SetWindowName("RenderWindowNoUIFile");
#else
    widget.GetRenderWindow()->AddRenderer(renderer);
    widget.GetRenderWindow()->SetWindowName("RenderWindowNoUIFile");
#endif
    widget.show();
    loop.exec();

    std::cout << "end" << std::endl;
}
