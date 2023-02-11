import logging


class MyAdapter:
    def __init__(self, logger, extra=None):
        self.logger = logger
        self.extra = extra or {}

    def log(self, level, msg, *args, **kwargs):
        self.logger.log(level, msg, *args, extra=self.extra, **kwargs)

    def info(self, msg, *args, **kwargs):
        self.log(logging.INFO, msg, *args, **kwargs)

    def error(self, msg, *args, **kwargs):
        self.log(logging.ERROR, msg, *args, **kwargs)

    def warning(self, msg, *args, **kwargs):
        self.log(logging.WARNING, msg, *args, **kwargs)
