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

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Game{
        id: game
    }

    Button {
        id: start_btn
        text: "Start"
        anchors.top: parent
        onClicked: {
            game.start()
            for(var index = 0; index < 64; index++)
                rep_img_pool.itemAt(index).source = game.getImage(index);
        }
    }

    Button {
        id: load_btn
        x: start_btn.width + 5
        text: "Load"
        anchors.bottom: parent
        onClicked: {
            addButton()
        }
    }
    Component {
        id: prev_btn;
        Button { }
    }
    Component {
        id: next_btn;
        Button { }
    }
    function addButton () {
            var button_prev = prev_btn.createObject(main_wnd,{
                                                        "x"      : load_btn.x + load_btn.width + 5,
                                                        "anchors.bottom": main_wnd,
                                                        "text": "prev"
                                                    });
        if (button_prev.status === button_prev.Ready){
            var button_next = next_btn.createObject(main_wnd,{
                                                        "x": button_prev.x + button_prev.width + 5,
                                                        "anchors.bottom": main_wnd,
                                                        "text": "next"
                                                    });
        }
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
                          if(game.movePiece(board.fromIndex, index)){
                              rep_img_pool.itemAt(index).source = rep_img_pool.itemAt(board.fromIndex).source
                              rep_img_pool.itemAt(board.fromIndex).source = ""
                          }
                          else
                              console.log("move is inpossible")
//                           game.saveMove();
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
