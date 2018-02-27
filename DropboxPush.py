import requests
import json
import dropbox
with open('DropboxKey.txt','r') as f:
    dbx = dropbox.Dropbox(f.read())
with open ("Puzzle3DS.cia","rb") as f:
    dbx.files_upload(bytes(f.read()),"/Puzzle3DS.cia",mode=dropbox.files.WriteMode.overwrite)
ciaLinkRaw=dbx.sharing_create_shared_link("/Puzzle3DS.cia",False)
ciaUrl=ciaLinkRaw.url.replace("www.dropbox","dl.dropboxusercontent").replace("?dl=0","")
GoogleQR=requests.get("https://chart.googleapis.com/chart?cht=qr&chl="+ciaUrl+"&chs=160x160&chld=L|0")
dbx.files_upload(GoogleQR.content,"/Puzzle3DS.png",mode=dropbox.files.WriteMode.overwrite)
pngLinkRaw=dbx.sharing_create_shared_link("/Puzzle3DS.png",False)
pngUrl=pngLinkRaw.url.replace("www.dropbox","dl.dropboxusercontent").replace("?dl=0","")
