import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import stood.game.chess 1.0
import stood.game.chess.piece 1.0

Window {
    id: main_wnd
    visible: true
    width: 360
    height: 400

    Game{
        id: game
        parent: main_wnd
    }

    Button {
        id: start_btn
        text: "Start"
        anchors.top: parent
        onClicked: {
                game.start()
                for(var index = 0; index < 64; index++)
                    rep_img_pool.itemAt(index).source = game.getImage(index);
                save_btn.visible = true
                stop_btn.visible = true
                start_btn.visible = false
                prev_btn.visible = false
                next_btn.visible = false
        }
    }

    Button {
        id: stop_btn
        text: "Stop"
        visible: false
        anchors.top: parent
        onClicked: {
            game.stop()
            for(var index = 0; index < 64; index++)
                rep_img_pool.itemAt(index).source = "";
            stop_btn.visible = false
            load_btn.visible = true
            save_btn.visible = false
            start_btn.visible = true
        }
    }

    Button {
        id: load_btn
        x: start_btn.width + 5
        text: "Load"
        anchors.bottom: parent
        onClicked: {
                prev_btn.visible = true;
                next_btn.visible = true;
                game.stop()
                for(var index = 0; index < 64; index++)
                    rep_img_pool.itemAt(index).source = "";
                game.start()
                for(var index = 0; index < 64; index++)
                    rep_img_pool.itemAt(index).source = game.getImage(index);
                game.load()
        }
    }

    Button {
        id: save_btn
        x: start_btn.width + 5
        text: "Save"
        anchors.bottom: parent
        visible: false
        onClicked: game.save();
    }

    Button {
        id: prev_btn
        x: load_btn.x + load_btn.width + 5
        anchors.bottom: main_wnd
        text: "prev"
        visible: false
        onClicked: game.prev()
    }

    Button {
        id: next_btn;
        x: prev_btn.x + prev_btn.width + 5
        anchors.bottom: main_wnd
        text: "next"
        visible: false
        onClicked: game.next()
    }

    function movePiece(fromIndex, toIndex){
        rep_img_pool.itemAt(toIndex).source = rep_img_pool.itemAt(fromIndex).source
        rep_img_pool.itemAt(fromIndex).source = ""
    }

    Grid {
        id:board
        y: start_btn.height
        visible: true
        width: main_wnd.width
        height: 360
        columns: 8
        spacing: 0
        rows: 8
        property int fromIndex: -1
        Repeater {
            id: rep
            model: 64
            Rectangle {
                id: rect
                width: parent.width / 8
                height: parent.height / 8
                color: ((Math.floor(index / 8) % 2) === 0)
                        ?
                        (index % 2  === 1 ? "#D18B47" : "#FFCE9E") // light brown &
                        :
                        (index % 2  === 0 ? "#D18B47" : "#FFCE9E")
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                       if (board.fromIndex === -1){
                           console.log(index%8 , Math.floor(index / 8))
                           board.fromIndex = index;
                           rect.border.width = 2;
                        }
                        else {
                           console.log("move from index " + board.fromIndex + " to " + index)
                           console.log("piece pos: %d, %d", parent.x, parent.y)
                           if(!game.movePiece(board.fromIndex, index)){
                               console.log("move is inpossible")
                          }
                           rep.itemAt(board.fromIndex).border.width = 0;
                          board.fromIndex = -1;
                       }
                      }
                  }
             }
        }
    }

    Grid {
        id:grid_img_pool
        y: start_btn.height
        visible: true
        width: main_wnd.width
        height: 360
        columns: 8
        spacing: 0
        rows: 8
        property int fromIndex: -1
        Repeater {
            id: rep_img_pool
            model: 64
            Image{
                Piece{
                    id: piece
                    property int w: grid_img_pool.width / 8
                    property int h: grid_img_pool.height / 8
                }
                id:image
                x: piece.x
                y: piece.y
                width: piece.w
                height: piece.h
            }
        }
    }
}

