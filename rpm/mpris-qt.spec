Name:       mpris-qt5

Summary:    Qt and QML MPRIS interface and adaptor
Version:    2.0.0
Release:    1
License:    LGPLv2
URL:        https://git.sailfishos.org/mer-core/qtmpris
Source0:    %{name}-%{version}.tar.bz2
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Qml)

%description
%{summary}.

%package devel
Summary:    Development files for %{name}
Requires:   %{name} = %{version}-%{release}

%description devel
Development files for %{name}.

%package qml-plugin
Summary:    QML plugin for %{name}
Requires:   %{name} = %{version}-%{release}

%description qml-plugin
QML plugin for %{name}.

%prep
%setup -q -n %{name}-%{version}

%build

%qmake5 VERSION=`echo %{version} | sed 's/+.*//'`

make %{?_smp_mflags}

%install
rm -rf %{buildroot}

%qmake5_install

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%license COPYING
%{_libdir}/lib*.so.*

%files devel
%defattr(-,root,root,-)
%{_datarootdir}/qt5/mkspecs/features/%{name}.prf
%{_includedir}/qt5/MprisQt/Mpris
%{_includedir}/qt5/MprisQt/MprisController
%{_includedir}/qt5/MprisQt/MprisManager
%{_includedir}/qt5/MprisQt/MprisPlayer
%{_includedir}/qt5/MprisQt/MprisService
%{_includedir}/qt5/MprisQt/mprisqt.h
%{_includedir}/qt5/MprisQt/mpris.h
%{_includedir}/qt5/MprisQt/mpriscontroller.h
%{_includedir}/qt5/MprisQt/mprismanager.h
%{_includedir}/qt5/MprisQt/mprisplayer.h
%{_includedir}/qt5/MprisQt/mprisservice.h
%{_libdir}/lib*.so
%{_libdir}/pkgconfig/%{name}.pc


%files qml-plugin
%defattr(-,root,root,-)
%{_libdir}/qt5/qml/Sailfish/Mpris/libmpris-qt5-qml-plugin.so
%{_libdir}/qt5/qml/Sailfish/Mpris/plugins.qmltypes
%{_libdir}/qt5/qml/Sailfish/Mpris/qmldir
%{_libdir}/qt5/qml/Sailfish/Mpris/MprisAudio.qml
