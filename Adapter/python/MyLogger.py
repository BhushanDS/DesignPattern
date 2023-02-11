import logging


class MyLogger:
    def __init__(self, name):
        self.logger = logging.getLogger(name)

    def info(self, message):
        self.logger.info(message)

    def error(self, message):
        self.logger.error(message)

    def warning(self, message):
        self.logger.warning(message)

    def log(self, level, message, *args, **kwargs):
        self.logger.log(level, message, *args, **kwargs)
