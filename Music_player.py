import pygame
import os
from tkinter import *
from tkinter import filedialog

# Initialize pygame mixer for sound
pygame.mixer.init()

# Function to play the selected music
def play_music():
    pygame.mixer.music.load(song_listbox.get(ACTIVE))
    pygame.mixer.music.play()

# Function to stop the music
def stop_music():
    pygame.mixer.music.stop()

# Function to pause the music
def pause_music():
    pygame.mixer.music.pause()

# Function to unpause the music
def unpause_music():
    pygame.mixer.music.unpause()

# Function to browse and load songs
def browse_songs():
    song = filedialog.askopenfilename(initialdir=os.getcwd(), title="Select A Song", filetypes=(("Text files", "*.mp3*"), ("All files", "*.*")))
    song_listbox.insert(END, song)

# Setting up the GUI
root = Tk()
root.title("Simple Music Player")

# Listbox to display song files
song_listbox = Listbox(root, width=50, height=15, bg="lightgrey", selectmode=SINGLE)
song_listbox.grid(row=0, column=0, columnspan=4)

# Buttons to control the player
play_button = Button(root, text="Play", width=10, command=play_music)
play_button.grid(row=1, column=0)

stop_button = Button(root, text="Stop", width=10, command=stop_music)
stop_button.grid(row=1, column=1)

pause_button = Button(root, text="Pause", width=10, command=pause_music)
pause_button.grid(row=1, column=2)

unpause_button = Button(root, text="Unpause", width=10, command=unpause_music)
unpause_button.grid(row=1, column=3)

# Browse button to add songs to the listbox
browse_button = Button(root, text="Browse", width=10, command=browse_songs)
browse_button.grid(row=2, column=0, columnspan=4)

# Run the GUI loop
root.mainloop()
