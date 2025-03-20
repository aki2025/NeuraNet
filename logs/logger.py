import logging

logging.basicConfig(filename='project.log', level=logging.INFO)

def log_event(event):
    logging.info(event) 
