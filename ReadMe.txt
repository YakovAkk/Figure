================================================== =======================
       MICROSOFT FOUNDATION CLASS LIBRARY: Figure 
================================================== =======================


I did the project as a term paper.
The file name of the file stores the points by which the program builds the polygon.
It is interesting in that, regardless of the order of the points in the file, the figure is built correctly.

Yakov has created this Figure  application for you. This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your cs_go application.

Figure .dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

Figure .h
    This is the main header file for the application. It includes other
    project specific headers (including Resource.h) and declares the
    CCs_goApp application class.

Figure .cpp
    This is the main application source file that contains the application
    class CCs_goApp.

Figure .rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses. It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory. This file can be directly edited in Microsoft
Visual C ++.

Figure .clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes. ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res \ Figure .ico
    This is an icon file, which is used as the application's icon. This
    icon is included by the main resource file cs_go.rc.

res \ cs_go.rc2
    This file contains resources that are not edited by Microsoft
Visual C ++. You should place all resources not editable by
the resource editor in this file.




//////////////////////////////////////////////// ///////////////////////////

AppWizard creates one dialog class:

cs_goDlg.h, cs_goDlg.cpp - the dialog
    These files contain your CCs_goDlg class. This class defines
    the behavior of your application's main dialog. The dialog's
    template is in cs_go.rc, which can be edited in Microsoft
Visual C ++.


//////////////////////////////////////////////// ///////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named cs_go.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C ++ reads and updates this file.

//////////////////////////////////////////////// ///////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C ++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL. ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.) If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

///////////////////////////////////////////////////////////////////////////
