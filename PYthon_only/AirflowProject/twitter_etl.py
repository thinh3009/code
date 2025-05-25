import tweepy

# Twitter API credentials
access_key = '8StACchkZTSTHk75PcUuE46Up'
access_secret = 'DGFMBD9AhO14SOKzUsrWa0R6eeRR7dW20waNmIr8QpgeBDtqx5'
consumer_key = '1122250626128171008-CLr4TmMLl6c7hU9wNqwOZoMrPIWnk1'
consumer_secret = 'UtLgyeliy6vueMfgZyws4XsVMi031Gp5YtKzYG54HKXNi'

# Twitter authentication using OAuth 1.0a
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_key, access_secret)

# Create an API object to interact with Twitter
api = tweepy.API(auth, wait_on_rate_limit=True)

# Get the most recent 200 tweets from Elon Musk's timeline
tweets = api.user_timeline(screen_name='elonmusk',
                           count=200,
                           include_rts=False,
                           tweet_mode='extended')

# Print out the tweets
for tweet in tweets:
    print(tweet.full_text)
