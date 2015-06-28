import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    id: main_wnd
    visible: true
    width: 360
    height: 400
    Rectangle {
        width: 360
        height: 360

        ListModel {
            id: dataModel
            ListElement{
                portrait: "img/bishop_black.png"
            }
            ListElement{
                portrait: "img/bishop_black.png"
            }
            ListElement{
                portrait: "img/bishop_black.png"
            }
            ListElement{
                portrait: "img/bishop_black.png"
            }
        }


        GridView {
            id: view

            width: parent.width
            height: parent.height
            model: dataModel
            clip: true

            delegate: Column{
                Image {
                    width: 45
                    height: 45
                    source: portrait
                }
            }
        }
    }
}
