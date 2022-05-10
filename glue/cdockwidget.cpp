// @snippet cdockwidget-setwidgetfactory
auto callable = %PYARG_1;
ads::CDockWidget::FactoryFunc callback = [callable](QWidget* widget) -> QWidget *
{
    if (!PyCallable_Check(callable)) {
        qWarning("Argument 1 of %FUNCTION_NAME must be a callable.");
        return NULL;
    }
    Shiboken::GilState state;
    Shiboken::AutoDecRef arglist(PyTuple_New(1));
    PyTuple_SET_ITEM(arglist, 0, %CONVERTTOPYTHON[QWidget*](widget));
    PyObject *ret(PyObject_CallObject(callable, arglist));
    QWidget *w = static_cast<QWidget *>(Shiboken::Conversions::cppPointer(SbkPySide2_QtWidgetsTypes[SBK_QWIDGET_IDX], reinterpret_cast<SbkObject *>(ret)));
    return w;

};
%CPPSELF.%FUNCTION_NAME(callback);
// @snippet cdockwidget-setwidgetfactory