from MyAdapter import MyAdapter
from MyLogger import MyLogger


my_logger = MyLogger('my_logger')
my_adapter = MyAdapter(my_logger, {'user_id': 123})

my_adapter.info('User Logged in')
my_adapter.error('An Error Occure')
my_adapter.warning('Something might be wrong')
